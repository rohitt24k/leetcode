class Solution {
    bool checkAns(vector<int> &nums, int k, int m){
        int count = 0;
        int sum = 0;

        for(auto i : nums){
            if(i > m) return false;

            sum += i;
            if(sum > m){
                count++;
                sum = i;
            }
        }

        if(count > k - 1) return false;

        if(sum <= m) return true;

        return false;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int totalSum = 0;

        for(auto i : nums){
            totalSum += i;
        }
        
        int s = 0;
        int e = totalSum;
        int ans = -1;

        while(s <= e){
            int m = (e - s)/2 + s;

            if(checkAns(nums, k, m)){
                ans = m;
                e = m - 1;
            }else{
                s = m + 1;
            }
        }  

        return ans;      
    }
};