class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowLength = matrix.size();
        int colLength = matrix[0].size();

        int startingRow = 0, endingRow = rowLength-1, startingCol = 0, endingCol = colLength-1;
        int max = rowLength * colLength;
        int count = 0;
        
        vector<int> ans;

        while(count < max){
            for(int i = startingCol; i <= endingCol && count < max; i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            for(int i = startingRow; i <= endingRow && count < max; i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            for(int i = endingCol; i >= startingCol && count < max; i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            for(int i = endingRow; i >= startingRow && count < max; i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};