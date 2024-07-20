class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        int sum = 0;
        int count = 0;
        hashmap[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            count += hashmap[sum-k];
            hashmap[sum]++;
        }
        return count;
    }
};