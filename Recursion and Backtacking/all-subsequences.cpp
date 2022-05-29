#include "/Users/nishant/bits/stdc++.h"
using namespace std;

void subseq(int idx, vector<int>&arr, vector<int> &result, int n){
    if (idx==n){
        for (auto i: result) cout << i << " ";
        if (result.size()==0) cout << "{}" << endl;
        cout << endl;
        return;
    }
    // take it
    result.push_back(arr[idx]);
    subseq(idx+1, arr, result, n);
    // Not take it
    result.pop_back();
    subseq(idx+1, arr, result, n);
}

int main(){
    vector<int> ar{3,1,2};
    vector <int> result;

    int idx=0;
    int n=3;

    subseq(idx, ar, result, n);

    return 0;
}