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
            if(vis[node]) return 0;
            vis[node] = 1;

            int curr = 0;
            for(int & neighbour : gr[node]) curr += dfs(dfs, neighbour);

            return 1 + curr;
        };

        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            // keeping the ith node and removing all the other nodes
            cnt += max(0, dfs(dfs, i) - 1); // if we only had one node in the component, we won't do anything
        }
        return cnt;
    }
};
