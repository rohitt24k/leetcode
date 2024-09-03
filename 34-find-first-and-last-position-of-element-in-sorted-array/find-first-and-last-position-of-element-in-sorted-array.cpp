class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int s = 0;
        int e = nums.size() - 1;
        int first = -1;

        while(s <= e){
            int m = ((e - s) / 2) + s;

            if(nums[m] == target){
                first = m;
                e = m - 1;
            }else if(nums[m] > target){
                e = m - 1;
            }else{
                s = m + 1;
            }
        }
        int last = -1;
        s = 0;
        e = nums.size() - 1;
        while(s <= e){
            int m = ((e - s) / 2) + s;

            if(nums[m] == target){
                last = m;
                s = m + 1;
            }else if(nums[m] > target){
                e = m - 1;
            }else{
                s = m + 1;
            }
        }

        return {first, last};
    }
};