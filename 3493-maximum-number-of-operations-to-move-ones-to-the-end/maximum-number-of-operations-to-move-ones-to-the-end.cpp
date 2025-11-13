class Solution {
public:
    int maxOperations(string s) {
        int groupCount = 0;
        bool jump = false;
        int ans = 0;

        for(auto c: s){
            if(c == '1'){
                if(jump){
                    ans += groupCount;
                }
                groupCount++;
                jump = false;
            }else{
                jump = true;
            }
        }

        if(jump){
            ans += groupCount;
        }

        return ans;
    }
};