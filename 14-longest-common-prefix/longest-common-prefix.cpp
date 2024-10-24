class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        string common(strs[0]);


        for(int i = 1; i < strs.size(); i++){
            string prestr = strs[i - 1];
            string currstr = strs[i];
            
            int s = 0;
            while(s < prestr.size() && s < currstr.size() && s < common.size() && prestr[s] == currstr[s]){
                s++;
            }

            if(s == 0) return "";
            common = currstr.substr(0, s);
        }   

        return common;      
    }
};