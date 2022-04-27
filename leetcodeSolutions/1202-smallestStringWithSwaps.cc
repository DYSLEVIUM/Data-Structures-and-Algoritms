class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        int m = pairs.size();
        
        vector<vector<int>> gr(n);
        for(auto &pair:pairs) {
            gr[pair[0]].push_back(pair[1]);
            gr[pair[1]].push_back(pair[0]);
        }
        
        vector<bool> vis(n, false);
        auto dfs = [&](const auto &dfs, const int &node, vector<int> &curr_comp){
            if(vis[node]) return;
            
            vis[node] = true;
            curr_comp.push_back(node);

            for(auto &neighbour: gr[node]) {
                dfs(dfs, neighbour, curr_comp);
            }
        };
        
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                vector<int> curr_comp;
                dfs(dfs, i, curr_comp);
                
                vector<char> v;
                for(int i = 0; i < curr_comp.size(); i++) {
                    v.push_back(s[curr_comp[i]]);
                }
                sort(v.begin(), v.end());
                sort(curr_comp.begin(), curr_comp.end());
                for(int i = 0; i < curr_comp.size(); i++) {   
                    s[curr_comp[i]] = v[i];
                }
            }
        }
        
        return s;
    }
};
