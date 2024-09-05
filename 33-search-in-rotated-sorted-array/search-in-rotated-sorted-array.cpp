class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0; 
        int e = nums.size() - 1;

        while(s <= e){
            int m = ((e - s) / 2) + s;
            if(target == nums[m]){
                return m;
            }else{
                if( nums[s] <= nums[m] && target >= nums[s] && target <= nums[m] ){
                    e = m - 1;
                }else if( nums[m] <= nums[e] && target >= nums[m] && target <= nums[e] ){
                    s = m + 1;
                }else if( nums[s] > nums[m] && ( target >= nums[s] || target <= nums[m] ) ){
                    e = m - 1;
                }else{
                    s = m + 1;
                }
            }
        }
        return -1;
    }
};