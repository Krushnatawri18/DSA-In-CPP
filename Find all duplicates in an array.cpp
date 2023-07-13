/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
  
Example 2:
Input: nums = [1,1,2]
Output: [1]
  
Example 3:
Input: nums = [1]
Output: []

Runtime - 328 ms
Memory - 111.1 MB

TC - O(N log N)
SC - O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums, int s, int e) {
      int mid = (s+e)/2;
  
      int len1 = mid - s + 1;
      int len2 = e - mid;
  
      int *first = new int[len1];
      int *second = new int[len2];
  
      //copy values
      int k = s;
      for(int i=0; i<len1; i++) {
          first[i] = nums[k++];
      }
  
      mainArrayIndex = mid+1;
      for(int i=0; i<len2; i++) {
          second[i] = nums[k++];
      }
  
      //merge 2 sorted arrays     
      int index1 = 0;
      int index2 = 0;
      mainArrayIndex = s;
  
      while(index1 < len1 && index2 < len2) {
          if(first[index1] < second[index2]) {
              nums[k++] = first[index1++];
          }
          else{
              nums[k++] = second[index2++];
          }
      }   
  
      while(index1 < len1) {
          nums[k++] = first[index1++];
      }
  
      while(index2 < len2 ) {
          nums[k++] = second[index2++];
      }
      delete []first;
      delete []second;
}

void mergeSort(vector<int>& nums, int s, int e) {
    //base case
    if(s >= e) {
        return;
    }
    int mid = (s+e)/2;

    // sorting left part
    mergeSort(nums, s, mid);
    
    // sorting right part
    mergeSort(nums, mid+1, e);

    //merge both parts
    merge(nums, s, e);
}

    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 1){
            return ans;
        }
        
        int n = nums.size() - 1;
        mergeSort(nums, 0, n);
        int i = 0;
        
        while(i < n){
            if(nums[i] == nums[i + 1]){
                ans.push_back(nums[i]);
                i++;
            }
            else{
                i++;
            }  
        }
        
    return ans;
    }
};

