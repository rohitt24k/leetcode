class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count1 = 0;

        for(int num: nums){
            if(num == 1) count1++;
        }

        if(count1 > 0) return nums.size() - count1;

        int minTimes = INT_MAX;

        for(int i = 0; i < nums.size() - 1; i++){
            int tempGcd = nums[i];
            for(int j = i+1; j < nums.size(); j++){
                tempGcd = gcd(tempGcd, nums[j]);
                if(tempGcd == 1) minTimes = min(minTimes, j-i);
            }
        }

        if(minTimes == INT_MAX) return -1;

        // cout<<"maxTimes="<<minTimes<<endl;

        return nums.size() + minTimes - 1;
    }
};