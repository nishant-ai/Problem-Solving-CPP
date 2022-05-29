#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int h[N] = {10, 30, 40, 20};
int dp[N];
int k;

// bruteforce recursion - Exponential Time Complexity
/*
int frog(int i){
    if (i==0) return 0;

    int cost = INT_MAX;
    // way 1
    cost = min(cost, frog(i-1) + abs(h[i] - h[i-1]));
    // way 2
    if(i > 1)
        cost = min(cost, frog(i-2) + abs(h[i] - h[i-2]));

    return cost;
}
*/

/*
FROG I Question:
https://atcoder.jp/contests/dp/tasks/dp_a
*/

// DP approach - memoisation - FROG I
int frog(int i){
    if (i==0) return 0;
    if (dp[i]!=-1) return dp[i];

    int cost = INT_MAX;
    // way 1
    cost = min(cost, frog(i-1) + abs(h[i] - h[i-1]));
    // way 2
    if(i > 1)
        cost = min(cost, frog(i-2) + abs(h[i] - h[i-2]));

    return dp[i] = cost;
}

/*
Frog II Question:
https://atcoder.jp/contests/dp/tasks/dp_b
*/

// DP approach - FROG II
int frog(int n){
    if (n==0) return 0;
    if (dp[n]!=-1) return dp[n];

    int cost = INT_MAX;
    
    for (int i=1; i<=k; i++){
        if (n-i>=0)
            cost = min(cost, frog(n-i) + abs(h[n] - h[n-1]));
    }

    return dp[n] = cost;
}

int main(){
    k = min(3, 3); // n, k
    memset(dp, -1, sizeof(dp));

    cout << frog(3) << endl;

    return 0;
}
