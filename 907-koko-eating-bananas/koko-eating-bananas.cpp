class Solution {

    bool isCorrectAns(vector<int> piles, int h, int m, int &ans) {
        for(int i = 0; i < piles.size(); i++){
            int currHour = ceil(static_cast<double>(piles[i]) / static_cast<double>(m));
            //cout<<currHour<<" ";
            h -= currHour;
        }

        if(h<0){
            return false;
        }else{
            ans = m;
            return true;
        }
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int highest = INT_MIN;
        int ans;

        for (int i = 0; i < piles.size(); i++) {
            highest = max(highest, piles[i]);
        }

        int s = 1;
        int e = highest;

        while (s <= e) {
            int m = ((e - s) / 2) + s;

            if(isCorrectAns(piles, h, m, ans)){
                //cout<<m<<" CORRECT"<<endl;
                e = m - 1;
            }else{
                //cout<<m<<" NOT"<<endl;
                s = m + 1;
            }
        }
        return ans;
    }
};