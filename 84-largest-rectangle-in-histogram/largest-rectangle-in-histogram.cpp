#include<stack>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        stack<pair<int, int>> s;
        vector<int> n(size, 0), p(size, 0);
        s.push({-1, size});
        for(int i = size - 1; i >= 0; i--){
            while(s.top().first >= heights[i]){
                s.pop();
            }
            n[i] = s.top().second;
            s.push({heights[i], i});
        }
        while(!s.empty()){
            s.pop();
        }
        s.push({-1, -1});
        for(int i = 0; i < size; i++){
            while(s.top().first >= heights[i]){
                s.pop();
            }
            p[i] = s.top().second;
            s.push({heights[i], i});
        }
        int max = 0;
        for(int i = 0; i < size; i++){
            int h = n[i] - p[i] - 1;
            int area = h * heights[i];
            if(area > max){
                max = area;
            }
        }
        return max;
    }
};