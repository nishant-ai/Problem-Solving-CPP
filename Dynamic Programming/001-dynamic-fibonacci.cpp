/*
Question: 

The Fibonacci sequence is a series where the next term is the sum of pervious two terms. The first two terms of the Fibonacci sequence is 0 followed by 1.
The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21 ...
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int dp[N];  //DP array

// dynamic fibonacci
int fib(int n){
    if (n==1 || n==0) return n;
    if (dp[n]!=-1) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2); // Store and return as well
}

int main(){

    memset(dp, -1, sizeof(dp)); // sets the values to -1 at all places;

    for (int i=0; i<10; i++)
        cout << fib(i) << endl;

    return 0;
}
