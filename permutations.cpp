/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Runtime 0 ms
Memory 7.5 MB
*/

class Solution {
public:
    void help(int pos,vector<int>&nums,vector<vector<int>>&ans){
        if(pos>=nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int i=pos; i<nums.size(); i++){
            swap(nums[pos],nums[i]);
            help(pos+1,nums,ans);
            swap(nums[i],nums[pos]);   // baclktracking to neutralize the effect made by swap
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int pos=0;
        help(pos,nums,ans);
        return ans;
    }
};
