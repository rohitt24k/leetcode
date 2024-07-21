class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size() - 1;
            int target = -1 * nums[i];
            while(j < k){
                int sum = nums[j] + nums[k];
                // cout<<sum<<endl;
                if(sum > target){
                    k--;
                }else if(sum < target){
                    j++;
                }else{
                    //we got the triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    //move the j to the new number as well as k
                    j++;
                    while(j < nums.size() && nums[j-1] == nums[j]) j++;
                    k--;
                    while( k > 0 && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};