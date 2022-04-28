class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        int ans = 0;
        
        auto check_bounds = [&](const int &x, const int &y){
            return (x >= 0 && y >= 0 && x < rows && y < cols);
        };
        
        vector<int> delta_x{1, 0, -1, 0}, delta_y{0, 1, 0, -1};
        vector<vector<bool>> vis(rows, vector<bool>(cols));
        
        using pi = pair<int, pair<int, int>>;   //  stores {effort, {x, y}}
        priority_queue<pi, vector<pi>, greater<pi>> min_heap;
        min_heap.push({0, {0, 0}});
        
        while(!min_heap.empty()) {
            auto tp = min_heap.top();
            min_heap.pop();
            
            int x = tp.second.first, y = tp.second.second;
            int effort = tp.first;
            
            if(vis[x][y]) continue;
            
            int ht = heights[x][y];
            vis[x][y] = true;
            ans = max(ans, effort);
            
            if(x == rows - 1 && y == cols - 1) return ans;
            
            for(int i = 0; i < 4; ++i) {
                int new_x = x + delta_x[i], new_y = y + delta_y[i];
                if(check_bounds(new_x, new_y)) {
                    min_heap.push({abs(ht - heights[new_x][new_y]), {new_x, new_y}});
                }
            }
        }
        
        //  unreachable code, if the path is valid
        return -1;
    }
};
