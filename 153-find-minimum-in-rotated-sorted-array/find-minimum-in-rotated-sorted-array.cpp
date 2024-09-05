class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        
        int low = 0;
        int high = nums.size() - 1;

        if(nums[low] <= nums[high]) return nums[low];

        while(s <= e){
            int m = ((e - s) / 2) + s;
            if(nums[low] <= nums[m] && nums[m + 1] <= nums[e]){
                return nums[m + 1];
            }else if(nums[low] <= nums[m]){
                s = m + 1;
            }else{
                e = m;
            }
        }
        return INT_MIN;
    }
};