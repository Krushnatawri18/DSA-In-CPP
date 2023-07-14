/*
Given an array arr[] of size N, check if it is sorted in non-decreasing order or not. 

Example 1:
Input:
N = 5
arr[] = {10, 20, 30, 40, 50}
Output: 1
  
Example 2:
Input:
N = 6
arr[] = {90, 80, 100, 70, 40, 30}
Output: 0

Runtime - 170 ms

Iteratively
TC - O(N)
SC - O(1)

Recursively
TC - O(N)
SC - O(N)
*/

class Solution {
  public:
  
    bool recursion(int arr[], int n){
        
        // base case
        if(n == 0 || n == 1){
            return 1;
        }
        
        if(arr[n - 2] > arr[n - 1]){
            return 0;
        }
        
        else{
            recursion(arr, n - 1);
        }
    }
  
    bool arraySortedOrNot(int arr[], int n) {
    // iteratively
    //     if(n == 0 || n == 1){
    //         return 1;
    //     }
        
    //     for(int i = 1; i < n  ; i++){
    //         if(arr[i - 1] > arr[i]){
    //             return 0;
    //         }
    //     }
    // return 1;
    
    bool ans = recursion(arr, n);
    return ans;
    
    }
};
