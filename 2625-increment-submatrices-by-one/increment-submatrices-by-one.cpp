class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        for(int i = 0; i < queries.size(); i++){
            int row1 = queries[i][0];
            int col1 = queries[i][1];
            int row2 = queries[i][2];
            int col2 = queries[i][3];

            ans[row1][col1] += 1;
            if(row2+1 < n && col2+1 < n) ans[row2+1][col2+1] += 1;
            if(col2+1 < n) ans[row1][col2+1] -= 1;
            if(row2+1 < n ) ans[row2+1][col1] -= 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                ans[i][j] +=ans[i][j-1];
            }
        }

        for(int j = 0; j < n; j++){
            for(int i = 1; i < n; i++){
                ans[i][j] += ans[i-1][j];
            }
        }

        return ans;
    }
};