class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int highest = INT_MIN;
        int lowest = INT_MAX;
        int maxi = 0;

        for( int i = 0; i < prices.size(); i++ ){
            highest = max(highest, prices[i]);

            if(prices[i] < lowest){
                lowest = prices[i];
                highest = 0;
            }

            maxi = max(maxi, highest - lowest);
        }
        return maxi;
    }
};