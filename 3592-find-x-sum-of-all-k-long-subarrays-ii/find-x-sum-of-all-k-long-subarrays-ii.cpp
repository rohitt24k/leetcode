class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> freq;
        set<pair<int, int>> top, rest; // pair<freq, num>
        long long topSum = 0;
        vector<long long> ans;

        for(int i = 0; i < k; i++){
            freq[nums[i]]++;
        }

        auto balance = [&](pair<int, int> p){ // pair<freq, num>
            /*
            first check with the weakest in the top which is the first element
            if the element incoming is strong remove the top element move it to the rest
            also update the topSum accordingly
            */

            // cout<<"working for first="<<p.second<<" second="<<p.first<<endl;
            if(top.size() >= x){
                auto topIt = top.begin();
                if(*topIt < p){
                    // cout<<"inserting first="<<p.second<<" second="<<p.first<<" removing first="<<topIt->second<<" second="<<topIt->first<<endl;
                    // insert into top
                    topSum -= ((long long)topIt->first * (long long)topIt->second);
                    topSum += ((long long)p.second * (long long)p.first);
                    rest.insert(*topIt);
                    top.erase(topIt);
                    top.insert(p);
                }else{
                    rest.insert(p);
                }
            }else{
                // cout<<"inserting first="<<p.second<<" second="<<p.first<<endl;
                top.insert(p);
                topSum += ((long long)p.second * (long long)p.first);
            }
        };

        for(const auto &it:freq){
            balance({it.second, it.first});
        }

        ans.push_back(topSum);


        int l = 1;
        int h = k;
        while(h < nums.size()){
            // cout<<"WOOOOAH"<<endl;
            pair<int, int> oldL = {freq[nums[l-1]], nums[l-1]};
            if(oldL >= *top.begin()){
                // first remove from top
                top.erase(oldL);
                if(rest.size() > 0){
                    auto newIt = --rest.end();
                    top.insert(*newIt);
                    topSum += ((long long)newIt->first * (long long)newIt->second);
                    rest.erase(newIt);
                }
                topSum -= ((long long)oldL.first * (long long)oldL.second);
            }else{
                rest.erase(oldL);
            }
            // remove the l elemnet
            freq[nums[l - 1]]--;

            if(freq[nums[l-1]] > 0) balance({freq[nums[l-1]], nums[l-1]});  

            pair<int, int> oldH = {freq[nums[h]], nums[h]};
            if(oldH >= *top.begin()){
                // first remove from top
                top.erase(oldH);
                if(rest.size() > 0){
                    auto newIt = --rest.end();
                    top.insert(*newIt);
                    topSum += ((long long)newIt->first * (long long)newIt->second);
                    rest.erase(newIt);
                }
                topSum -= ((long long)oldH.first * (long long)oldH.second);
            }else{
                rest.erase(oldH);
            }
            // add the h element
            freq[nums[h]]++;

            balance({freq[nums[h]], nums[h]});
                

            ans.push_back(topSum);   
            h++;
            l++; 
        }

        return ans;
    }
};