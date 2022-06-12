// https://leetcode.com/problems/maximum-erasure-value/

#include "/Users/nishant/bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map <int, int> m;
        int n = nums.size();
        int global_max = 0, local_sum=0;
        int start=0, end=0;
        
        while(end<n){
            local_sum += nums[end];
            
            while (m.find(nums[end])!=m.end()){
                local_sum-=nums[start];
                m.erase(nums[start]);
                start++;
            }
            
            global_max = max(global_max, local_sum);
            m[nums[end]]=end;
            end++;
        }
        
        return global_max;
    }
};