#include <bits/stdc++.h>
using namespace std;

int dp[10010];

int bruteForce(vector<int>&coins, int amount){ // Recursion
    int ans = INT_MAX;
    if (dp[amount]!=-1) return dp[amount];
    if (amount==0) return 0;
    for (int coin: coins){
        if (amount-coin >= 0)
        ans = min(bruteForce(coins, amount-coin) + 1LL, ans + 0LL);
    }
    return dp[amount] = ans;
}

int coinChange(vector<int>&coins, int amount){
    int ans = bruteForce(coins, amount);
    return (ans == INT_MAX) ? -1 : ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    vector <int> coins{1, 2, 5};
    cout << coinChange(coins, 11) << endl;

    return 0;
}