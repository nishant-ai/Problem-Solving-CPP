// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector <string> ans;
    vector <string> m{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void backtrack(int i, string curStr, string digits){
        // Base Case
        if (curStr.length()==digits.length()){
            ans.push_back(curStr);
            return;
        }
        
        for (char c: m[digits[i]-'0']){ // char to int
            backtrack(i+1, curStr+c, digits);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        if (digits.length()!=0){
            backtrack(0, "", digits);
        }
        
        return ans;
    }
};