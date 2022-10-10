class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int area = n * n, cnt0 = 0;
        for(int i = 0; i < n; ++i) {
            int maxx_r = INT_MIN, maxx_c = INT_MIN;
            for(int j = 0; j < n; ++j) {
                maxx_r = max(maxx_r, grid[i][j]);
                maxx_c = max(maxx_c, grid[j][i]);
                cnt0 += grid[i][j] == 0;
            }
            area += maxx_r + maxx_c;
        }
        area -= cnt0;

        return area;
    }
};
