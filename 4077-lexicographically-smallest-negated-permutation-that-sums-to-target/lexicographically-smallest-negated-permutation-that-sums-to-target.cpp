class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long sum = 0;
        long long remaining = (long long)n * ((long long)n + 1) / 2;
        vector<int> ans;

        for(int i = n; i >= 1; i--){
            remaining -= i;
            if(sum - i + remaining >= target){
                ans.push_back(-i);
                sum -= i;
            }else{
                ans.push_back(i);
                sum += i;
            }
        }    

        if(sum == target){
            sort(ans.begin(), ans.end());
            return ans;
        }else{
            return {};
        }
    }
};