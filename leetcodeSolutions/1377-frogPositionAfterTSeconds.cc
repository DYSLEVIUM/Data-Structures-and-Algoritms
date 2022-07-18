class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> tree(n + 1);
        for(auto &edge: edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        auto dfs = [&](const auto &dfs, const int &node, const int &parent, const int &time) -> double {
            if(time < 0) {
                return 0;
            }
            
            int curr_child_cnt = tree[node].size() - (node != 1);
            if(node == target) {
                if(curr_child_cnt == 0 && time >= 0) {
                    return 1;
                } else if(curr_child_cnt && time == 0) {
                    return 1;
                }
            }
            
            double ans = 0;
            for(auto &child: tree[node]) {
                if(child != parent) {
                    ans += (1.0 / curr_child_cnt) * dfs(dfs, child, node, time - 1);
                }
            }
            
            return ans;
        };
        
        return dfs(dfs, 1, 0, t);
    }
};
