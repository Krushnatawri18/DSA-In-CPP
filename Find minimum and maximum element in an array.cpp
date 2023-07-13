/*
Given an array A of size N of integers. Your task is to find the minimum and maximum elements in the array.

Example 1:
Input:
N = 6
A[] = {3, 2, 1, 56, 10000, 167}
Output:
min = 1, max =  10000

Runtime  - 400 ms

TC - O(N log N)
SC - O(1)
*/

pair<long long, long long> getMinMax(long long a[], int n) {
    
    long long mini;
    long long maxi;
    
    sort(a, a + n);
    mini = a[0];
    maxi = a[n - 1];
    
    return make_pair(mini, maxi);
    
}
