class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> gr(n);
        set<pair<int, int>> se;
        for(vector<int> & connection : connections) {
            gr[connection[0]].push_back(connection[1]);
            gr[connection[1]].push_back(connection[0]);
            se.insert({connection[0], connection[1]});
        }

        vector<int> vis(n);
        auto dfs = [&](const auto & dfs, const int & node, const int & par){
            if(vis[node]) {
                return 0;
            }
            vis[node] = 1;
            
            int ans = se.find({par, node}) != se.end(); // if the edge is opposite, we reverse it

            for(int & neigh : gr[node]) {
                ans += dfs(dfs, neigh, node);
            }

            return ans;
        };

        return dfs(dfs, 0, -1);
    }
};
