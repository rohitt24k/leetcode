class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while(s < e){
            int m = ((e - s)/2) + s;

            if( nums[m] == nums[m-1]){
                int rightSize = e - m+1 + 1;
                int leftSize = m-2 - s + 1;

                if(rightSize % 2 != 0){
                    s = m + 1;
                }else{
                    e = m - 2;
                }
            }else if(nums[m] == nums[m+1]){
                int rightSize = e - m+2 + 1;
                int leftSize = m-1 - s + 1;

                if(rightSize % 2 != 0){
                    s = m + 2;
                }else{
                    e = m - 1;
                }
            }else{
                return nums[m];
            }
        }

        return nums[s];
    }
};