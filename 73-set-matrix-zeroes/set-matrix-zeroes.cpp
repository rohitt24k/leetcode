class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rows[row];
        int cols[col];

        for(int i = 0; i < row; i++){
            rows[i] = 1;
        }
        for(int i = 0; i < col; i++){
            cols[i] = 1;
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for(int i = 0; i < row; i++){
            if(rows[i] == 0){
                for(int j = 0; j < col; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j = 0; j < col; j++){
            if(cols[j] == 0){
                for(int i = 0; i < row; i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};