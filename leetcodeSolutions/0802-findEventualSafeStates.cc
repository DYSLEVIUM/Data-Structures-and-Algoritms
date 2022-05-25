class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<bool> is_visited(n);
        vector<bool> on_stack(n);
        auto dfs = [&](const auto &dfs, const int &node) -> bool {
            on_stack[node] = true;
            is_visited[node] = true;
            
            for(auto &neighbour: graph[node]) {
                if(!is_visited[neighbour]) {
                    if(!dfs(dfs, neighbour)) {
                        return false;
                    }
                } else if(on_stack[neighbour]) {
                    return false;
                }
            }

            on_stack[node] = false;
            
            return true;
        };
        
        vector<int> safe;
        for(int node = 0; node < n; ++node) {
            if(dfs(dfs, node)) safe.push_back(node);
        }
        
        return safe;
    }
};
