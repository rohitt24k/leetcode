class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> freq(1001, 0);

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        while(true){
            if(original < freq.size() && freq[original] > 0){
                original *= 2;
            }else{
                break;
            }
        }

        return original;
    }
};