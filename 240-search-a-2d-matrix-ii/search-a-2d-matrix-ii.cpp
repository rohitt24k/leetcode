class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // start from the bottom left

        int x = matrix.size();
        int y = matrix[0].size();

        int u = 0;
        int v = y - 1;

        while( v >= 0 && u < x){
            if(matrix[u][v] == target){
                return true;
            }else if(matrix[u][v] < target){
                u++;
            }else{
                v--;
            }
        }
        return false;
    }
};