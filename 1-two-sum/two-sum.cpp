class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
                vector<int> ans;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            int adder = target - nums[i];
            if(m.find(adder) != m.end()){
                ans.push_back(i);
                ans.push_back(m[adder]);
                return ans;
            }else{
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};