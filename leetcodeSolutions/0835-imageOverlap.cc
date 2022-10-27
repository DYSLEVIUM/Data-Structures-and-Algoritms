class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int n = img1.size();
        auto dfs = [&](const auto & dfs, const int & dr, const int & dc){
            int curr = 0;
            for(int row = 0; row < n; ++row) {
                for(int col = 0; col < n; ++col) {
                    int new_row = row + dr, new_col = col + dc;
                    if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= n) continue;
                    // translating only img1
                    curr += img1[new_row][new_col] * img2[row][col];
                }
            }
            return curr;
        };
    
        int ans = 0;
        for(int dr = -n + 1; dr < n; ++dr) {
            for(int dc = -n + 1; dc < n; ++dc) ans = max(ans, dfs(dfs, dr, dc));
        }
        return ans;
    }
};
