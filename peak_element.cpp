# cpp

/*
Find Peak Element

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int ans;
        int j=0;
        if(nums.size()==1)
        {
            ans=0;
        }
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i+1]<nums[i])
            {
                ans=i;
                break;
            }
            else
            {
                ans=i+1;
            }
        }
    return ans;    

    }
};
