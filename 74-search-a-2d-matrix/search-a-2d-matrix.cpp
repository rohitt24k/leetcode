class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix.size();
        int y = matrix[0].size();
        
        // first find in which row

        int s = 0;
        int e = x - 1;

        
        while(s<=e){
            int m = s + (e - s) / 2;

            if(matrix[m][0] == target){
                return true;
            }else if(matrix[m][0] > target){
                e = m - 1;
            }else{
                s = m + 1;
            }
        }

        int u = e;

        if(u < 0 || u >= x) return false;

        s = 0;
        e = y - 1;

        while(s <= e){
            int m = s + (e - s) / 2;

            if(matrix[u][m] == target){
                return true;
            }else if(matrix[u][m] > target){
                e = m - 1;
            }else{
                s = m + 1;
            }
        }

        return false;      
    }
};