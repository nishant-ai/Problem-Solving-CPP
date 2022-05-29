#include <bits/stdc++.h>
using namespace std;
// fibonacii number

int fib(int n){
/*
    First the fib(n-1) will exec, then whenever the value is returned to the call,
    fib(n-2) will exec to get its return val.
    and, finally when we have both fib(n-1) and fib(n-2); their sum will be returned to the earlier call.
*/

    if (n<=1) return n;
    int last = fib(n-1); // next 3 lines are same as "return fib(n+1) + fib(n+2)"
    int slast = fib(n-2);
    return last+slast;
}

int main(){
    cout << fib(3);

    return 0;
}