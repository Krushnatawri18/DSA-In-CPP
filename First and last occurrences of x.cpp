/*
Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Example 1:
Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
  
Example 2:
Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  6 6 

Runtime - 290 ms

TC - O(log N)
SC - O(1)
*/

int binarySearchforFirst(int arr[], int x, int n)
{
    int s = 0; 
    int e = n - 1;
    int res = -1;
    while (s <= e) {
 
        int mid = (s + e) / 2;
 
        if (arr[mid] > x){
            e = mid - 1;
        }
        else if (arr[mid] < x){
            s = mid + 1;
        }
 
        else {
            res = mid;
            e = mid - 1;
        }
    }
    return res;
}

int binarySearchforLast(int arr[], int x, int n)
{
    int s = 0; 
    int e = n - 1;
    int res = -1;
    while (s <= e) {
 
        int mid = (s + e) / 2;
 
        if (arr[mid] > x){
            e = mid - 1;
        }
            
        else if (arr[mid] < x){
            s = mid + 1;
        }

        else {
            res = mid;
            s = mid + 1;
        }
    }
    return res;
}

vector<int> find(int arr[], int n , int x )
{
    int first = binarySearchforFirst(arr,x,n);
    int last = binarySearchforLast(arr,x,n);
    vector<int> ans;
    ans.push_back(first);
    ans.push_back(last);
  
    return ans;    
}
