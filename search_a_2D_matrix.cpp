# cpp

Search a 2D Matrix

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 
Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) 
            return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int s = 0;
        int e = (n*m)-1;
        
        while(s<=e)
        {
            int mid = (s +(e-s)/2);
            if(matrix[mid/m][mid%m]==target)
                return true;
            
            if(matrix[mid/m][mid%m]<target)
                s = mid+1;
            else
                e = mid-1;
        }
        return false;
    }
};
