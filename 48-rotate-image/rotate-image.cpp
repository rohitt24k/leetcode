class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //first find the transpose

        for(int i = 0; i < m; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int left = 0;
        int right = n -1;

        while(left < right){
            for(int i = 0; i < m; i++){
                swap(matrix[i][left], matrix[i][right]);
            }
            left++;
            right--;
        }
    }
};