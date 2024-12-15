class Solution {
public:
    string reverseWords(string s) {

        // first make a word and keep it into a stack

        string currWord = "";
        stack<string> stk;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(currWord != ""){
                    stk.push(currWord);
                    currWord = "";
                }
            }else{
                currWord += s[i];
            }
        }

        if(currWord != ""){
            stk.push(currWord);
        }

        string ans = "";

        while(stk.size() > 1){
            string temp = stk.top();
            ans += temp;
            ans += " ";
            stk.pop();
        }

        string temp = stk.top();
            ans += temp;
            stk.pop();



        return ans;
    }
};