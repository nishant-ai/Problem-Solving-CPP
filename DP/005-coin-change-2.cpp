// Question: https://leetcode.com/problems/coin-change-2/

#include <bits/stdc++.h>
using namespace std;

// Without Dynamic Programming
int bruteForce(int idx, int amount, vector<int>& coins){
    if (amount==0) return 1;
    if (idx<0) return 0;

    int ways = 0;
    for (int coin_am=0; coin_am<=amount; coin_am+=coins[idx]){
        ways += bruteForce(idx-1, amount-coin_am, coins);
    }
    return ways;
}

// With Dynamic Programming - Leet Code ACCEPTED solution
class Solution {
public:
    int dp[310][10010]; // DP
     
    int bruteForce(int idx, int amount, vector<int>& coins){
        if (amount==0) return 1;
        if (idx<0) return 0;
        if (dp[idx][amount]!=-1) return dp[idx][amount]; // DP

        int ways = 0;
        for (int coin_am=0; coin_am<=amount; coin_am+=coins[idx]){
            ways += bruteForce(idx-1, amount-coin_am, coins);
        }
        return dp[idx][amount] = ways; // DP
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp)); // DP
        return bruteForce(coins.size()-1, amount, coins);
    }
};

int change(int amount, vector<int>& coins) {
    return bruteForce(coins.size()-1, amount, coins);
}

int main(){
    vector<int>coins{1, 2, 5};
    cout << change(5, coins) << endl;

    return 0;
}
