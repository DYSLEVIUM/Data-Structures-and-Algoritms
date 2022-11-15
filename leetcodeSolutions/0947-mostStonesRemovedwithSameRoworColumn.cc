class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<vector<int>> gr(n);
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) 
                    gr[i].push_back(j), gr[j].push_back(i);
            }
        }

        vector<int> vis(n);
        auto dfs = [&](const auto & dfs, const int & node){
            if(vis[node]) return ;
            vis[node] = 1;
            for(int & neighbour : gr[node]) dfs(dfs, neighbour);
        };

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) dfs(dfs, i), ++ans;
        }
        return n - ans;
    }
};
