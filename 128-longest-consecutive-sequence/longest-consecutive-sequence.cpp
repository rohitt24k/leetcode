class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st;
        int largest = 1;

        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        } 

        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i] - 1) == st.end()){
                int x = nums[i];
                int count = 0;

                while(st.find(x) != st.end()){
                    x++;
                    count++;
                }
                largest = max(largest, count);
            }
        }       
        return largest;
    }
};