class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if(!rows) {
            return 0;
        }
        
        if(rows == 1) {
            return triangle[0][0];
        }

        const int INF = INT_MAX / 2;
        for(int row = 1; row < rows; ++row) {
            int cols = triangle[row].size();
            int prev_cols = triangle[row - 1].size();
            
            for(int col = 0; col < cols; ++col) {
                int left_side = col - 1 >= 0 ? triangle[row - 1][col - 1] : INF;
                int top_side = col < prev_cols ? triangle[row - 1][col] : INF;
                
                triangle[row][col] += min(left_side, top_side);
            }
        }
        
        int minn = INF;
        for(int &last_col_num: triangle[rows - 1]) {
            minn = min(minn, last_col_num);
        }
        
        return minn;
    }
};
