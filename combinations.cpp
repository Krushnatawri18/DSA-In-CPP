/*

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

Example 2:
Input: n = 1, k = 1
Output: [[1]]

Runtime 34 ms
Memory 18.2 MB

*/
class Solution {
public:
    void help(int n, int k, vector<vector<int>>& ans, vector<int>& subset,int i){

        if(i>n){
          // k = 0 means we have filled k elements in an array
            if(k==0){
                ans.push_back(subset);
            }
            return;
        }

        // including the i th element
        subset.push_back(i);
        help(n,k-1,ans,subset,i+1);

        // excluding the i th element
        subset.pop_back();
        help(n,k,ans,subset,i+1);

    }


    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> subset;
        int i=1;
        help(n,k,ans,subset,i);
        return ans;
    }
};
