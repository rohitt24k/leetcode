class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> freq(26, 0);
        for(auto c: s){
            freq[c - 'a']++;
        }

        int ans = 0;

        for(int i = 0; i < 26; i++){
            if(freq[i] < 2) continue;

            char c = 'a' + i;

            // first find the first index and the last index of occurence of char
            // then count the total unique chars between them and update ans
            
            int start = 0;
            while(s[start] != c) start++;
            int end = s.size() - 1;
            while(s[end] != c) end--;

            set<char> uniqueChars;
            for(int j = start + 1; j < end; j++){
                uniqueChars.insert(s[j]);
            }

            ans += uniqueChars.size();
        }

        return ans;
    }
};