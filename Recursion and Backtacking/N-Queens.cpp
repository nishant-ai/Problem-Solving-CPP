#include "/Users/nishant/bits/stdc++.h"
using namespace std;

// Hashing Method
/*
class Solution {
public:
    void solve(int col, vector<string>&board, vector<vector<string>>&ans, vector<int>&leftRow, vector<int>&upperDiag, vector<int>&lowerDiag, int n){
        // base case
        if (col==n){
            ans.push_back(board);
            return;
        }
        
        for (int row=0; row<n; row++){
            if (leftRow[row]==0 && upperDiag[row+col]==0 && lowerDiag[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiag[n-1+col-row]=1;
                upperDiag[col+row]=1;
                
                solve(col+1, board, ans, leftRow, upperDiag, lowerDiag, n);
                    
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiag[n-1+col-row]=0;
                upperDiag[col+row]=0;
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n, '.');
        
        for (int i=0; i<n; i++) board[i] = s;
        
        vector <int> leftRow(n, 0), upperDiag(2*n-1, 0), lowerDiag(2*n-1, 0);
        solve(0, board, ans, leftRow, upperDiag, lowerDiag, n);
        return ans;
    }
};
*/

// Simplest Method
/*
class Solution {
public:
    
    bool isSafe(int row, int col, vector<string>&board, int n){
        // duplicates to restore val to check each case
        int r = row;
        int c = col;
        
        // check upper diagonal
        while(row>=0 && col>=0){
            if (board[row--][col--]=='Q') return false;
        }
        
        row=r;
        col=c;
        //check lower diagonal
        while (row<n && col >=0)
            if (board[row++][col--]=='Q') return false;
        
        row=r;
        col=c;
        // check left
        while(col>=0)
            if (board[row][col--]=='Q') return false;
        
        // if all cases pass!
        return true;
    }
    
    // BackTracking
    void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n){
        if (col==n){
            ans.push_back(board);
            return;
        }
        
        for (int row=0; row<n; row++){
            if (isSafe(row, col, board, n)){
                board[row][col]='Q';
                solve(col+1, board, ans, n);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n, '.');
        
        for (int i=0; i<n; i++) board[i] = s;
        
        solve(0, board, ans, n);
        return ans;
    }
};
*/

// My Own Method - Maths


int main(){
    Solution sol;
    vector<vector<string>>ans = sol.solveNQueens(8);
    int i=0;

    for (auto ds: ans){
        cout << "Solution #" << i++ << endl;
        cout << "-----------------" << endl;
        for (string s: ds){
            cout << s << endl;
        }
    }

    cout << "-----------------" << endl;

    return 0;
}