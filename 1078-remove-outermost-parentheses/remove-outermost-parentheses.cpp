class Solution {
public:
    string removeOuterParentheses(string s) {
        bool removed = false;
        int balanced = 0;
        string ans("");
        for(int i = 0; i < s.size(); i++){
            if(!removed && s[i] == '('){
                removed = true;
            }else if(balanced == 0 && s[i] == ')'){
                removed = false;
            }else if(s[i] == '(') {
                ans += s[i];
                balanced++;
            }else{
                ans += s[i];
                balanced--;
            }
        }

        return ans;
    }
};