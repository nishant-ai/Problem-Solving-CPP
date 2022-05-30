#include "/Users/nishant/bits/stdc++.h"
using namespace std;
// Subsequences with a sum mentioned

void subSeqSum(int idx, int target, vector<int>&a, int sum, vector<int>&h){
    if (idx==a.size()){ 
        if (sum==target){
            for (int i: h) cout << i << " ";
            cout << endl;
        }
        return;
    }
    // take
    sum+=a[idx];
    h.push_back(a[idx]);
    subSeqSum(idx+1, target, a, sum, h);
    // Not take
    sum-=a[idx];
    h.pop_back();
    subSeqSum(idx+1, target, a, sum, h);
}

int main(){
    vector<int> a{1, 2, 1};
    vector<int>h; // helper
    subSeqSum(0, 2, a, 0, h);

    return 0;
}