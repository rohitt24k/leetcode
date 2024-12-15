class Solution {
public:

    bool check(string s, string goal, int i){
        for(int j = 0; j < s.size(); j++){
            if(s[i] == goal[j]){
                i++;
                i = i % s.size();
            }else{
                return false;
            }
        }
        return true;
    }

    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == goal[0] && check(s, goal, i)){
                return true;
            }
        }
        return false;
    }
};