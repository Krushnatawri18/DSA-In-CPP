/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Runtime 15 ms
Memory 10.7 MB
TC O(2 raised to n)
SC O(n)

*/
#include<bits/stdc++.h>
class Solution {
public:

    void helper(int i,vector<int>& candidates, int target,int sumTillNow,vector<int>&subset,vector<vector<int>>& ans){

        // base case
        if(sumTillNow == target){
            ans.push_back(subset);
            return;
        }

        if(sumTillNow > target){
            return;
        }

        if(i >= candidates.size()){
            return;
        }

        // include
        sumTillNow += candidates[i];
        subset.push_back(candidates[i]);
        helper(i+1,candidates,target,sumTillNow,subset,ans);
        sumTillNow -= candidates[i];   // backtracking to neutralize the effect
        subset.pop_back();      // backtracking to neutralize the effect

        // exclude
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]){
            i++;
        }
        helper(i+1,candidates,target,sumTillNow,subset,ans);
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sumTillNow = 0;
        vector<int> subset;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());            // sorting before going to help()
        helper(0,candidates,target,sumTillNow,subset,ans);
        sort(ans.begin(),ans.end());            // sorting aftercoming from help()
        return ans;
    }
};
