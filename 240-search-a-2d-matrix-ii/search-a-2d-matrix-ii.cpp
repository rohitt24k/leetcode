class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // start from the bottom left

        int x = matrix.size();
        int y = matrix[0].size();

        for(int v = y-1; v >= 0; v--){
            if(target < matrix[0][v]) continue;

            int s = 0;
            int e = x - 1;

            while(s <= e){
                int m = s + (e - s) / 2;

                if(matrix[m][v] == target){
                    return true;
                }else if(matrix[m][v] > target){
                    e = m - 1;
                }else{
                    s = m + 1;
                }
            }
        }
        return false;
    }
};