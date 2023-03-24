/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

Runtime 7 ms
Memory 17 MB
TC O(2 raised to n)
SC O(n)

*/

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

        // exclude
        helper(i+1,candidates,target,sumTillNow,subset,ans);

        // include
        sumTillNow += candidates[i];
        subset.push_back(candidates[i]);
        helper(i,candidates,target,sumTillNow,subset,ans);
        sumTillNow -= candidates[i];   // backtracking to neutralize the effect
        subset.pop_back();      // backtracking to neutralize the effect

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sumTillNow=0;
        vector<int> subset;
        vector<vector<int>> ans;
        helper(0,candidates,target,sumTillNow,subset,ans);
        return ans;


    }
};
