#include <iostream>
#include <vector>
using namespace std;

void subseq(int idx, vector<int> ar, vector <vector<int> > &result, int n){
    vector <int> temp;
    if (idx==n){
        result.push_back(temp);
        return;
    }
    // take it
    temp.push_back(ar[idx]);
    subseq(idx+1, ar, result, n);
    // Not take it
    temp.pop_back();
    subseq(idx+1, ar, result, n);
}

int main(){
    vector<int> ar;
    vector <vector<int> > result;
    int idx=0;
    int n=ar.size()-1;

    subseq(idx, ar, result, n);

    for (auto i: result){
        cout << "[ ";
        for (auto j: i)
            cout << j << " ";
        cout << " ]" << endl;
    }
    return 0;
}