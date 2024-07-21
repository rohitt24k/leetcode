class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1, num2;
        int count1 = 0, count2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == num1){
                count1++;
            }else if(nums[i] == num2){
                count2++;
            }else if(count1 == 0 && num2 != nums[i]){
                num1 = nums[i];
                count1++;
            }else if(count2 == 0 && num1 != nums[i]){
                num2 = nums[i];
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        

        vector<int> ans;
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            cout<<num1<<" "<<count1<<endl;
            if(nums[i] == num1){
                count1++;
            }else if(nums[i] == num2){
                count2++;
            }
        }
        // cout<<num1<<" "<<count1<<endl;
        int target = nums.size() / 3;
        if(count1 > target) ans.push_back(num1);

        if(count2 > target) ans.push_back(num2);

        return ans;
    }
};