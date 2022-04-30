class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        
        unordered_map<string, vector<pair<string, double>>> gr;
        for(int i = 0; i < n; ++i) {
            auto &equation = equations[i];
            string &nume = equation[0], &denom = equation[1];

            gr[nume].push_back({denom, values[i]});
            gr[denom].push_back({nume, 1.0 / values[i]});
        }
        
        unordered_set<string> vis;
        auto dfs = [&](const auto &dfs, const string &src, const string &dest){
            if(src == dest) return 1.0;
            
            for(auto &node: gr[src]) {
                if(vis.count(node.first)) continue;
                vis.insert(node.first);
                
                double res = dfs(dfs, node.first, dest);
                if(res != -1.0) return res * node.second;
            }
            
            return -1.0;
        };
        
        vector<double> ans;
        for(auto &query: queries) {
            string &nume = query[0], &denom = query[1];

            if(gr.find(nume) == gr.end() || gr.find(denom) == gr.end()) {
                ans.push_back(-1);
                continue;
            }
            
            vis.clear();
            ans.push_back(dfs(dfs, nume, denom));
        }
        
        return ans;
    }
};
