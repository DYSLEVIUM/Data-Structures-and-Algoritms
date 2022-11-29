class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;

        // rotate the matrix to pi/4 from top right end, the matrix looks like a BST, use this property

        int row = 0, col = cols - 1;
        while(row < rows && col >= 0) {
            int curr = matrix[row][col];
            if(curr == target) return true;
            if(curr > target) --col;
            else ++row;
        }

        return false;
    }
};
