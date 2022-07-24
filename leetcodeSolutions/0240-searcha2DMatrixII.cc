class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;

        //  in any sub-matrix of this kind, the last-row, last-col will have the biggest value and the first row, first col will have the smallest value, so at a time we either reduce a row or a column => time complexity is O(n + m)
        int row = 0, col = cols - 1;
        while(row < rows && col >= 0) {
            if(matrix[row][col] == target) {
                return true;
            }
            
            matrix[row][col] > target ? --col : ++row;
        }
        
        return false;
    }
};
