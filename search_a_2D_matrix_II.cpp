/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
  
Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
  
Runtime 146 ms
Memory 14.8 MB
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        // start from the [first row, last column] element
        int rowInd = 0;
        int colInd = col-1;

        while(rowInd < row  && colInd >= 0){

            if(matrix[rowInd][colInd] == target)  // target found
                return true;

            else if(matrix[rowInd][colInd] > target) //target is smaller, go leftwards
                --colInd;             // decrease the column index
            else                // target is larger, go downwards
                ++rowInd;       // increase the row index
        }

        return false;          // target not found
    }
};
 
