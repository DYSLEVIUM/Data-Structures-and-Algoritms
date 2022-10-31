class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
        for(int row = 0; row < rows - 1; ++row) {
            for(int col = 0; col < cols - 1; ++ col) {
                if(row + 1 <= rows && col + 1 <= cols && matrix[row][col] != matrix[row + 1][col + 1]) return false; 
            }
        }
        return true;
    }
};

class Solution1 {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
        // all the elements, except the elements in the last row and the last column have a pair which in row major form lies ahead with a constant distance of cols + 1, so for all the valid index we check the if the pairs are equal
        for(int row = 0; row < rows - 1; ++row) {
            for(int col = 0; col < cols - 1; ++ col) {
                int other = (row * cols + col) + cols + 1;
                if(other >= rows * cols) continue;

                int other_row = other / cols, other_col = other % cols;
                if(matrix[row][col] != matrix[other_row][other_col]) return false;
            }
        }
        return true;
    }
};
