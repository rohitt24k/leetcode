class Solution {
public:
    string largestOddNumber(string num) {

        for(int i = num.size(); i >= 0; i--){
            char c = num[i];
            if(c == '1' || c == '3' || c == '5' || c == '7' || c == '9'){
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};