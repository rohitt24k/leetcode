class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalSum = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            totalSum += i;
            sum += nums[i];
        }

        totalSum += nums.size();
        
        return totalSum - sum;
    }
};