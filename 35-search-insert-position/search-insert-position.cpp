class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while(s < e){
            int m = ((e - s) / 2) + s; 
            cout<< m<<endl;
            if(nums[m] == target){
                return m;
            }else if( nums[m] > target ){
                e = m - 1;
            }else {
                s = m + 1;
            }
        }
        
        if(target > nums[nums.size() - 1]){
            return nums.size();
        }

        if(s == e){
            if(nums[s] < target){
                return s + 1;
            }
        }

        return s;
    }
};