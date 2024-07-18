class Solution {
public:
    int justBada(vector<int> &nums, int startIndex, int baseNum){
        int ans = INT_MAX;
        int index;

        for(int i = startIndex; i < nums.size(); i++){
            if(nums[i] > baseNum){
                ans = min(ans, nums[i]);
                index = i;
            }
        }

        return index;
    }
    
    void nextPermutation(vector<int>& nums) {
        int prev = INT_MIN;
        for( int i = nums.size() - 1; i >= 0; i-- ){
            if(nums[i] < prev){
                int index = justBada(nums, i+1, nums[i]);
                swap(nums[i], nums[index]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
            prev = nums[i];
        }
        sort(nums.begin(), nums.end());
    }
};