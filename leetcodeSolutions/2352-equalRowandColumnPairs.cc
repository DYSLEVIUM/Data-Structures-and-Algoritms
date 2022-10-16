class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_multiset<string> se;
        for(auto &row : grid) {
            string curr;
            for(auto &col : row) {
                curr += to_string(col);
                curr += " ";
            }
            se.insert(curr);
        }

        int cnt = 0;
        for(int j = 0; j < n; ++j) {
            string curr;
            for(int i = 0; i < n; ++i) {
                curr += to_string(grid[i][j]);
                curr += " ";
            }
            cnt += se.count(curr);
        }
        
        return cnt;
    }
};
