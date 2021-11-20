class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<bool> vis(graph.size(), false);

        auto dfs = [&](const auto& dfs, const int& node, const vector<int> currAns){
            if(vis[node]) return;
            
            if(node == graph.size()-1) {
                ans.push_back(currAns);
                return;
            }
            
            vis[node] = true;

            for(auto neighbour: graph[node]){
                vector<int> pt(currAns.begin(), currAns.end());
                pt.push_back(neighbour);
                
                dfs(dfs, neighbour, pt);
            }
                        
            vis[node] = false;
        };
        
        dfs(dfs, 0, vector<int>(1,0));
        
        return ans;
    }
};
