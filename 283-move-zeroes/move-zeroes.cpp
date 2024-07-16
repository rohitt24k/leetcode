class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int index = -1;
        for(int i = 0; i < nums.size(); i++ ){
            if(nums[i] == 0 && index == -1) index = i;

            if(index != -1 && nums[i] != 0){
                swap(nums[index], nums[i]);
                index = index + 1;
            }
        }
        
    }
};