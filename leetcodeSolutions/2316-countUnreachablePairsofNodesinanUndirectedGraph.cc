class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(n);
        for(auto & edge : edges) {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n);
        auto dfs = [&](const auto & dfs, const int & node){
            if(vis[node]) {
                return 0;
            }
            vis[node] = 1;

            int curr = 1;
            for(auto & neigh : gr[node]) {
                curr += dfs(dfs, neigh);
            }

            return curr;
        };

        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            int cnt = dfs(dfs, i);
            ans += 1LL * cnt * (n - cnt);
        }

        ans >>= 1; // removing overcounting of a->b and b->a

        return ans;
    }
};
