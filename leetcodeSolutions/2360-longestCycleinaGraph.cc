class Solution {
public:
    int longestCycle(vector<int>& edges) {
        static const int INF = 0x3f3f3f3f;
        int n = edges.size();

        int ans = -1; // assuming we have no cycles
        vector<int> vis(n);
        auto dfs = [&](const auto & dfs, const int & node, const int & iter, unordered_map<int, int> & mp){
            if(edges[node] == -1) {
                return ;
            }

            if(vis[node]) {
                if(mp.count(node)) {
                    ans = max(ans, iter - mp[node]); // all the nodes between are in the cycle
                }
                return ;
            }
            vis[node] = 1;

            mp[node] = iter; // abusing the fact that there can only be atmost one outgoing edge
            dfs(dfs, edges[node], iter + 1, mp);
            mp.erase(node); // remove from the current stack
        };

        for(int i = 0; i < n; ++i) {
            if(vis[i]) {
                continue;
            }

            unordered_map<int, int> mp;
            dfs(dfs, i, 0, mp);
        }

        return ans == 1 ? -1 : ans; // cycle of 1 doesn't make sense
    }
};
