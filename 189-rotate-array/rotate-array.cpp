class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> ans(size);
        for( int i = 0; i < nums.size(); i++ ){
            int index = (i + k) % size;
            ans[index] = nums[i];
        }
        nums = ans;
    }
};