class Solution {
public:
    string largestOddNumber(string num) {
        int size = -1;

        for(int i = 0; i < num.size(); i++){
            char c = num[i];
            if(c == '1' || c == '3' || c == '5' || c == '7' || c == '9'){
                size = i;
            }
        }

        return num.substr(0, size + 1);
    }
};