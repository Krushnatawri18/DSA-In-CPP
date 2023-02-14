/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Runtime 0 ms
Memory 6.8 MB
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int total = row*col;
        int count = 0;

        int sr=0,er=row-1;
        int sc=0,ec=col-1;

        while(count<total){

            for(int i=sc; i<=ec && count<total; i++){
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            
            for(int j=sr; j<=er && count<total; j++){
                ans.push_back(matrix[j][ec]);
                count++;
            }
            ec--;
            
            for(int k=ec; k>=sc && count<total; k--){
                ans.push_back(matrix[er][k]);
                count++;
            }
            er--;

            for(int m=er; m>=sr && count<total; m--){
                ans.push_back(matrix[m][sc]);
                count++;
            }
            sc++;
          
        }
    
    return ans;
    }
};
