class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        int prev = -101;
        int count = 0;

        for( int i = 0; i < nums.size(); i++ ){
            if(nums[i] != prev){
                ans.push_back(nums[i]);
                prev = nums[i];
                count++;
            }
        }

        nums = ans;
        return count;
    }
};