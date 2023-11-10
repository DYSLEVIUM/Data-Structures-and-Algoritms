class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        constinit static int INF = 0x3f3f3f;

        int n = adjacentPairs.size();

        unordered_map<int, vector<int>> gr;
        for(const auto & pair: adjacentPairs) {
            int u = pair[0], v = pair[1];

            gr[u].push_back(v);
            gr[v].push_back(u);
        }

        int root = INF; // inf
        for(const auto &[node, neigh]: gr) {
            if(neigh.size() == 1) {
                root = node;
                break;
            }
        }

        vector<int> ans;
        ans.reserve(n);

        auto dfs = [&](const auto & dfs, const int & node, const int & prev) -> void {
            ans.push_back(node);

            for(const auto & neigh: gr[node]) {
                if(neigh == prev) {
                    continue;
                }
                dfs(dfs, neigh, node);
            }
        };

        dfs(dfs, root, INF);

        return ans;
    }
};
