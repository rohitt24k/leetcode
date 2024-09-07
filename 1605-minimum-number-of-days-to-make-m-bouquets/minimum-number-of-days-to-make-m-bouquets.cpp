class Solution {
    bool isCorrectAns(vector<int> &bloomDay, int m, int k, int mid){
        int count = 0;

        for( int i = 0; i < bloomDay.size(); i++ ){
            if(bloomDay[i] <= mid){
                count++;
                if(count == k){
                    m--;
                    count = 0;
                    if(m == 0){
                        return true;
                    }
                }
            }else{
                cout<<"i = "<<i<<" ";
                if(static_cast<long long>(m) * k > (bloomDay.size() - i)){
                    //cout<<"*"<<m*k<<"-"<<bloomDay.size() - i<<"*";
                    return false;
                }
                count = 0;
            }
        }

        if(m <= 0){
            return true;
        }else{
            return false;
        }
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        //return -1;
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

        int s = 1;
        int e = maxDay;
        int ans = -1;

        while(s <= e){
            int mid = ((e - s)/2) + s;
            cout<<mid<<" ";
            if(isCorrectAns(bloomDay, m, k, mid)){
                e = mid - 1;
                ans = mid;
            }else{
                s = mid + 1;
            }
            cout<<endl;
        }
        return ans;
        
    }
};