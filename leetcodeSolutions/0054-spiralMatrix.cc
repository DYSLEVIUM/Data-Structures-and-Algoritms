class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        //  empty matrix
        if(matrix.size() == 0) return ans;
        
        int rows = matrix.size(), cols = matrix[0].size();
        
        int top = 0, left = 0, bottom = rows - 1, right = cols - 1;
        
        while(top<=bottom && left<=right){
            //  top row
            for(int j=left;j<=right;++j) ans.push_back(matrix[top][j]);
            ++top;
            
            //  checking this condition again as only a single row matrix can exist itself
            if(top>bottom) break;
            
            //  right column
            for(int i=top;i<=bottom;++i) ans.push_back(matrix[i][right]);
            --right;
            
            //  checking this condition again as only a single column matrix can exist itself
            if(left>right) break;
            
            //  bottom row
            for(int j=right;j>=left;--j) ans.push_back(matrix[bottom][j]);
            --bottom;
            
            //  left column
            for(int i=bottom;i>=top;--i) ans.push_back(matrix[i][left]);
            ++left;
        }
        
        return ans;
    }
};
