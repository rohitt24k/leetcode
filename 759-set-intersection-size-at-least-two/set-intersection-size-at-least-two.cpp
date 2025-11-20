class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // elements till prevHigh is included
        int last = intervals[0][1];
        int secondLast = intervals[0][1]-1;
        int ans = 2; // 2 numbers are included from the first

        // for(auto v: intervals){
        //     cout<<"["<<v[0]<<","<<v[1]<<"]"<<",";
        // }
        // cout<<endl;
        for(int i = 1; i < intervals.size(); i++){
            vector<int> prev = intervals[i-1];
            auto curr = intervals[i];
            // cout<<ans<<endl;

            if(secondLast >= curr[0]){
                // means both are included
                secondLast = min(secondLast, curr[1]-1);
                last = min(last, curr[1]);
            }else if(last >= curr[0]){
                // only 1 is included
                secondLast = min(last, curr[1]-1);
                last = curr[1];
                ans += 1;
            }else{
                // none included
                last = curr[1];
                secondLast = curr[1] - 1;
                ans += 2;
            }
        }

        return ans;
    }
};