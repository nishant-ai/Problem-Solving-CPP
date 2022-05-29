#include <bits/stdc++.h>
using namespace std;
// Sum of numbers upto n

// Paramaterised way
/*
void sumUp(int sum, int n){
    if (n==0){
        cout << sum << endl;
        return;
    }
    sumUp(sum+n, n-1);
}
*/

// Functional way
/*
int sumUp(int n){
    if (n==1) return 1;
    return sumUp(n-1)+n;
}
*/

int main(){
    cout << sumUp(3);

    return 0;
}