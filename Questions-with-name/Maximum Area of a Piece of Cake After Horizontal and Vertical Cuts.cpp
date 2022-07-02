#include "/Users/nishant/bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long long int max_h = horizontalCuts[0], max_v = verticalCuts[0];
        
        for (int i=1; i<horizontalCuts.size(); i++)
            max_h = (horizontalCuts[i]-horizontalCuts[i-1] > max_h) ? horizontalCuts[i]-horizontalCuts[i-1] : max_h;
        
        for (int i=1; i<verticalCuts.size(); i++)
            max_v = (verticalCuts[i]-verticalCuts[i-1] > max_v) ? verticalCuts[i]-verticalCuts[i-1] : max_v;
        
        return (max_h*max_v)%1000000007;
    }
};