/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9

Example 3:
Input: k = 4, n = 1
Output: []

Runtime 0 ms
Mmemory 6.7 MB
TC O(2 raised to n)
SC O(n)
*/

#include<bits/stdc++.h>
class Solution {
public:

    void helper(int i,int k, int n,int sumTillNow,vector<int>&subset,vector<vector<int>>& ans){

        // base case
        if(k == 0){
            if(sumTillNow == n){
                ans.push_back(subset);
            }
            return;
        }

        if(sumTillNow > n){
            return;
        }

        if(i >= 10){
            return;
        }

        // include
        sumTillNow += i;
        subset.push_back(i);
        helper(i+1,k-1,n,sumTillNow,subset,ans);
        sumTillNow -= i;        // backtracking to neutralize the effect
        subset.pop_back();      // backtracking to neutralize the effect

        // exclude
        helper(i+1,k,n,sumTillNow,subset,ans);
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        int sumTillNow = 0;
        vector<int> subset;
        vector<vector<int>> ans;
        helper(1,k,n,sumTillNow,subset,ans);
        return ans;
    }
};
