// Question: https://leetcode.com/problems/longest-increasing-subsequence/
#include <iostream>
#include <vector>
using namespace std;


int a[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
int n = sizeof(a);

// Normal Approach
// ---------------------------------------------------------------------------------------------------
int lis(int n){
    int ans = 1;
    for (int i=0; i<n; ++i){
        if (a[n] > a[i]) ans = max(ans, lis(i)+1);
    }

    return ans;
}
// ---------------------------------------------------------------------------------------------------


// DP Approach
// ---------------------------------------------------------------------------------------------------
const int N = 1e5+10;
int dp[N];

int lis(int n){ // returns the length only
    if (dp[n] != -1) return dp[n];
    int ans = 1;

    for (int i=0; i<n; ++i){
        if (a[n] > a[i]) ans = max(ans, lis(i)+1);
    }

    return dp[n] = ans;
}
//---------------------------------------------------------------------------------------------------


// LEETCODE SOLUTION WITH DP
//---------------------------------------------------------------------------------------------------
class Solution {
public:
    int dp[2501];
    
    int lis(int n, vector<int>&a){
        if (dp[n] != -1) return dp[n];
        int ans = 1;

        for (int i=0; i<n; ++i){
            if (a[n] > a[i]) ans = max(ans, lis(i, a)+1);
        }

        return dp[n] = ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        
        for (int i=0; i<n; i++)
            ans = max(lis(i, nums), ans);
        
        return ans;
    }
};
//---------------------------------------------------------------------------------------------------


int main(){
    memset(dp, -1, sizeof(a));
    int ans = 0;

    for (int i=0; i<n; i++){
        cout << ans << ' ';
        ans = max(lis(i), ans);
    }

    cout << endl << ans << endl;

    return 0;
}
