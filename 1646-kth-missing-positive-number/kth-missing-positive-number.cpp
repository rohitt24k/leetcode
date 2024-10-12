class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0;
        int previousElement = 0;

        for(int i : arr){
            int missing = i - previousElement - 1;
            missingCount += missing;

            if(missingCount >= k){
                int prevMissingCount = missingCount - missing;
                int offset = k - prevMissingCount;
                int ans = previousElement + offset;
                return ans;
            }

            previousElement = i;
        }

        int offset = k - missingCount;

        return previousElement + offset;
    }
};