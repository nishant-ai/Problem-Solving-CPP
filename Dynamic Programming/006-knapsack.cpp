// 0-1 Knapsack Problem
#include "/Users/nishant/bits/stdc++.h"
using namespace std;

int wt[10010];
int val[10010];

// BruteForce-Knapsack
int knapSack(int n, int w){ // n - no. of items | w - weight of knapsack
    
    // Edge Cases
    if (w<=0) return 0; 
    if (n<=0) return 0;

    if (wt[n-1]>w) return knapSack(n-1, w); // if wt of item > weight left in knapsack

    return max(knapSack(n-1, w), knapSack(n-1, w-wt[n-1]) + val[n-1]);
}

// DP - memoised KnapSack
int dp[10010][10010]; // n, w
int knapSack(int n, int w){ // n - no. of items | w - weight of knapsack
    
    // Edge Cases
    if (w<=0) return 0; 
    if (n<=0) return 0;

    // if found in memo
    if (dp[n][w]!=-1) return dp[n][w];

    // if wt of item > weight left in knapsack
    if (wt[n-1]>w) return knapSack(n-1, w);

    // Common Case
    return dp[n][w] = max(knapSack(n-1, w), knapSack(n-1, w-wt[n-1]) + val[n-1]);
}

int main(){
    memset(dp, -1, sizeof(dp)); // For DP

    int n;
    cin >> n;

    for(int i=0; i<n; i++) cin >> wt[i];
    for(int i=0; i<n; i++) cin >> val[i];

    int w;
    cin >> w;
    cout << knapSack(n, w) << endl;

    return 0;
}