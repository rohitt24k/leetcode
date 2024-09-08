class Solution {

    bool isSol(vector<int> &nums, int threshold, int m){
        int sum = 0;

        for( int i = 0; i < nums.size(); i++){
            sum += ceil(static_cast<double>(nums[i])/m);
            //cout<<nums[i]<<" ceil "<<m<<"->"<<ceil(static_cast<double>(nums[i])/m)<<" ";
            if(sum > threshold){
                return false;
            }
        }

        return true;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxiDivisor = *max_element(nums.begin(), nums.end());

        int s = 1;
        int e = maxiDivisor;

        while(s <= e){
            int m = ((e - s) / 2) + s;

            if(isSol(nums, threshold, m)){
                e = m - 1;
            }else{
                s = m + 1;
            }
            //cout<<endl;
        }
        return s;
    }
};