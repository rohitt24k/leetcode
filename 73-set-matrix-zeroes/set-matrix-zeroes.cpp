class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> v;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    v.push_back({i, j});
                }
            }
        }

        for(auto it : v){
            int x = it.first;
            int y = it.second;

            for( int i = 0; i < m; i++){
                matrix[i][y] = 0;
            }

            for( int i = 0; i < n; i++){
                matrix[x][i] = 0;
            }
        }
    }
};