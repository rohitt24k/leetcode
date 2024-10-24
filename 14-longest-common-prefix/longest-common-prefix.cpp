class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int preSize = 0;
        char pre;
        
        while(true){
            for(int i = 0; i < strs.size(); i++){
                string s = strs[i];
                if(s.size() == preSize){
                    return s.substr(0,preSize);
                }
                if(i == 0){
                    pre = s[preSize];
                    continue;
                }
                if(s[preSize] != pre){
                    return s.substr(0,preSize);
                }
            }

            preSize++;
        }  

        return "";  
    }
};