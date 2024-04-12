/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *current = root;
        while(current != NULL){
            //if the current does not have left child in the case print the current's data and go the right i.e. current = current -> right
            if(current -> left == NULL){
                ans.push_back(current -> val);
                current = current -> right;
            }
            // else find the rightmost node in current left subtree or node whose right child == current
            else{
                TreeNode *temp = current -> left;
                while(temp -> right != NULL && temp -> right != current){
                    temp = temp -> right;
                }
                //now we have that rightmost in the temp
                if(temp -> right != NULL){
                    temp -> right = NULL;
                    ans.push_back(current -> val);
                    current = current -> right;
                }else{
                    temp -> right = current;
                    current = current -> left;
                }
            }
        }
        return ans;
    }
};