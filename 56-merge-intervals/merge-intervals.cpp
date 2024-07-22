class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int prevStart = -1;
        int prevEnd = -1;

        for(int i = 0; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start <= prevEnd){
                // cout<< start <<" "<< prevEnd<<endl;
                prevEnd = max(end, prevEnd);
            }else{
                if(prevEnd != -1)
                    ans.push_back({prevStart, prevEnd});
                prevStart = start;
                prevEnd = end;
            }
        }
        if(prevEnd != -1)
            ans.push_back({prevStart, prevEnd});
        return ans;
    }
};