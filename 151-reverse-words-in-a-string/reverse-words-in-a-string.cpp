class Solution {
public:
    string reverseWords(string s) {
        string word("");
        string ans("");

        for(auto c: s){
            if(c == ' '){
                if(ans.size() != 0 && word.size() > 0) ans = " " + ans;
                ans = word + ans;
                word = "";
            }else{
                word += c;
            }
        }

        if(ans.size() != 0 && word.size() > 0) ans = " " + ans;
        ans = word + ans;

        return ans;
    }
};