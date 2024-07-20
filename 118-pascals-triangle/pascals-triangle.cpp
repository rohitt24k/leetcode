class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev({1});
        ans.push_back(prev);
        numRows--;

        while(numRows--){
            vector<int> preans;
            preans.push_back(1);
            for(int i = 1; i < prev.size(); i++){
                preans.push_back(prev[i-1] + prev[i]);
            }
            preans.push_back(1);
            ans.push_back(preans);
            prev = preans;
        }

        return ans;
    }
};