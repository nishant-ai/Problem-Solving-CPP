#include "/Users/nishant/bits/stdc++.h"
using namespace std;

// Approach-1 Mapping
class Solution1{
    public:
    void recurPermute(vector<int>&temp, vector<int>&nums, vector<vector<int>>&ans, int freq[]){
        if (temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for (int i=0; i<nums.size(); i++){
            if (!freq[i]){
                temp.push_back(nums[i]);
                freq[i]=1;
                recurPermute(temp, nums, ans, freq);
                temp.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>&nums){
        vector<vector<int>> ans;
        vector<int> temp;

        int freq[nums.size()];
        for (int i=0; i<nums.size(); i++) freq[i]=0;
        recurPermute(temp, nums, ans, freq);

        return ans;
    }
};

// Approach-2 : Swapping
class Solution2{
    public:
    void recurPermute(int index, vector<int>&nums, vector<vector<int>>&ans){
        if (index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for (int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            recurPermute(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>&nums){
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};

int main(){
    Solution2 sol;

    vector<int> test{1, 2, 3};
    vector<vector<int>>a = sol.permute(test);
    
    for (auto i: a){
        for (int j: i) cout << j << " ";
        cout << endl;
    }

    return 0;
}