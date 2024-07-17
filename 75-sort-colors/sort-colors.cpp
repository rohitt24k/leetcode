class Solution {
public:
    void handleSwap(vector<int> &nums, int &zeroIndex, int &oneIndex, int swapIndex ){
        if(nums[swapIndex] == 1 && oneIndex < nums.size()){
            if(oneIndex < zeroIndex){
                oneIndex = zeroIndex;
            }
            swap(nums[oneIndex++], nums[swapIndex]);
        }else if(nums[swapIndex] == 0 && zeroIndex < nums.size()){
            swap(nums[zeroIndex++], nums[swapIndex]);
            if(nums[swapIndex] == 1){
                handleSwap(nums, zeroIndex, oneIndex, swapIndex);
            }
        }
    }

    void sortColors(vector<int>& nums) {
        int zeroIndex = 0;
        int oneIndex = 0;

        for( int i = 0; i < nums.size(); i++ ){
           if(nums[i] != 2){
                handleSwap(nums, zeroIndex, oneIndex, i);
           }
        }
    }
};