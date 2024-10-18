class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int x = mat.size();
        int y = mat[0].size();

        int s = 0;
        int e = y - 1;

        while(s <= e){
            int m = s + (e - s)/2;

            //find the max in the column m;

            int maxi = INT_MIN;
            int maxiIndex = -1;

            for(int u = 0; u < x; u++){
                if(maxi < mat[u][m]){
                    maxi = mat[u][m];
                    maxiIndex = u;
                }
            }

            bool left = m == 0;
            bool right = m == y-1;

            if(!left) left = mat[maxiIndex][m - 1] < mat[maxiIndex][m];
            if(!right) right = mat[maxiIndex][m + 1] < mat[maxiIndex][m];

            if(left && right) return {maxiIndex, m};
            else if(!left){
                e = m - 1;
            }else{
                s = m + 1;
            }
        }

        return {-1,-1};
    }
};