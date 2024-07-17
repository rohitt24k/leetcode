class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prenum;

        for( int i = 0; i < nums.size(); i++ ){
            int needed = target - nums[i];

            if(prenum.find(needed) != prenum.end()){
                return {prenum[needed], i};
            }else{
                prenum.insert({nums[i], i});
            }
        }
        return {0, 0};
    }
};