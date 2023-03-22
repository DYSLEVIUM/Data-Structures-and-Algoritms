class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        constexpr int INF = 0x3f3f3f3f;
        
        vector<vector<pair<int, int>>> gr(n);
        for(auto & road : roads) {
            --road[0], --road[1];
            gr[road[0]].push_back({road[1], road[2]});
            gr[road[1]].push_back({road[0], road[2]});
        }

        vector<int> vis(n);
        auto dfs = [&](const auto & dfs, const int & node, const int & score){
            if(vis[node]) {
                return INF;
            }

            vis[node] = 1;

            int minn = score;
            for(auto & [neigh, weight] : gr[node]) {
                minn = min(minn, weight); // either this edge
                minn = min(minn, dfs(dfs, neigh, minn)); // from rest of the path
            }

            return minn;
        };

        return dfs(dfs, 0, INF);
    }
};
