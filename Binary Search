/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
  
Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
  
Runtime 49 ms
Memory 27.6 MB
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s=0,e=nums.size()-1;

        int mid = s+(e-s)/2;

        while(s <= e){

            if(nums[mid]  == target){
                return mid;
            }

            else if(nums[mid] > target){
                e = mid-1;
            }
            
            else{
                s = mid+1;
            }

            mid = s+(e-s)/2;
        
        }
    return -1;
    }
};
