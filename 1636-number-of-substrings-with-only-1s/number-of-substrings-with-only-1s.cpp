class Solution {
public:
    int numSub(string s) {
        queue<int> zeroPosition;

        zeroPosition.push(-1);

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '0') zeroPosition.push(i);
        }

        zeroPosition.push(s.size());

        int prev = zeroPosition.front();
        zeroPosition.pop();

        int ans = 0;
        int MAXI = 1000000007;

        while(!zeroPosition.empty()){
            int curr = zeroPosition.front();
            zeroPosition.pop();

            long long n = curr - prev - 1;
            int currAns = (n * (n + 1) / 2) % MAXI;

            currAns = max(0, currAns);
            
            // cout<<"checking for pos="<<curr<<" currAns="<<currAns<<endl;
            ans = (ans + currAns) % MAXI;
            prev = curr;
        }

        return ans;
    }
};