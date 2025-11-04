class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        // for the first k elements
        unordered_map<int, int> freq;
        
        for(int i = 0; i < k; i++){
            freq[nums[i]]++;
        }

        // now build a set
        set<pair<int,int>> s;
        for(auto it:freq){
            s.insert({it.second, it.first});
        }        

        vector<int> ans;

        // now sliding window
        int l = 0;
        int h = k-1;

        while(h <  nums.size()){
            // get the top x elements from the set
            // cout<<"set "<<endl;
            // for(auto it: s){
            //     cout<<it.second<<"="<<it.first<<" ";
            // }
            // cout<<endl;

            auto it = s.end();
            it--;
            int sum = 0;
            for(int i = 0; i < x && i < s.size(); i++){
                sum += it->first * it->second;
                it--;
            }

            ans.push_back(sum);

            // now update the set
            if(h == nums.size() - 1) break;
            h++;
            int lcount = freq[nums[l]];
            s.erase({lcount, nums[l]});
            s.insert({lcount - 1, nums[l]});

            freq[nums[l]]--;

            int hcount = freq[nums[h]];
            s.erase({hcount, nums[h]});
            s.insert({hcount + 1, nums[h]});

            freq[nums[h]]++;
            l++;
        }

        return ans;
    }
};