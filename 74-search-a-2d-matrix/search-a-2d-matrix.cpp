class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix.size();
        int y = matrix[0].size();
        
        int low = 0;
        int high = x * y - 1;

        while(low <= high){
            int m = low + (high - low) / 2;

            int u = m / y;
            int v = m % y;
            if(matrix[u][v] == target){
                return true;
            }else if(matrix[u][v] > target){
                high = m - 1;
            }else{
                low = m + 1;
            }
        }  

        return false;      
    }
};