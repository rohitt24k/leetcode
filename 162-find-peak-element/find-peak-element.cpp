class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        
        while(s <= e){
            int m = ((e - s)/2) + s;
            int prev = INT_MIN;
            int next = INT_MIN;

            if(m-1 >=0 ) prev = nums[m-1];
            if(m+1 < nums.size()) next = nums[m+1];

            if(nums[m] >= prev && nums[m] >= next){
                return m;
            }else if(nums[m] >= prev){
                s = m + 1;
            }else{
                e = m - 1;
            }
        }
        return -1;
    }
};