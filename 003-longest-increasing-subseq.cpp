//  https://youtu.be/mNrzyuus2h4
#include <bits/stdc++.h>
using namespace std;


// Normal Approach
int a[] = {10, 22, 9, 33, 21, 50, 41, 60, 80}; // {1, 11, 90, 13, 99, 100, 101, 109, 120, 25, 998, 998, 999, 999, 1000, 1023, 1098, 1200, 1980, 2000};
int n = sizeof(a);

/*
int lis(int n){
    int ans = 1;
    for (int i=0; i<n; ++i){
        if (a[n] > a[i]) ans = max(ans, lis(i)+1);
    }

    return ans;
}
*/


// DP Approach
const int N = 1e5+10;
int dp[N];

int lis(int n){
    if (dp[n] != -1) return dp[n];
    int ans = 1;

    for (int i=0; i<n; ++i){
        if (a[n] > a[i]) ans = max(ans, lis(i)+1);
    }

    return dp[n] = ans;
}


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