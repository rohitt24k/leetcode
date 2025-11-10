class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            while(!st.empty() && st.top() > num)
                st.pop();

            if(num == 0) continue;

            if(st.empty() || st.top() < num){
                st.push(num);
                ans++;
            }
        }

        return ans;
    }
};