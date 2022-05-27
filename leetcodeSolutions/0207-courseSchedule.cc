class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //  if the graph has a cycle, its not possible
        vector<vector<int>> gr(numCourses);
        for(auto prerequisite: prerequisites) {
            int &u = prerequisite[0];
            int &v = prerequisite[1];
            
            gr[u].push_back(v);
        }
        
        vector<bool> visited(numCourses);
        vector<bool> curr_stack(numCourses);
        auto dfs = [&](const auto &dfs, const int &node){
            if(curr_stack[node]) return false;
            if(visited[node]) return true;
            
            visited[node] = true;
            curr_stack[node] = true;
            
            for(auto &neighbour: gr[node]) {
                if(!dfs(dfs, neighbour)) {
                    return false;
                }
            }
            
            curr_stack[node] = false;
            return true;
        };
        
        for(int i = 0; i < numCourses; ++i) {
            if(!dfs(dfs, i)) {
                return false;
            }
        }
        
        return true;
    }
};
