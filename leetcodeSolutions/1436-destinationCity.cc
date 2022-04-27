class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> left;
        for(auto &path: paths) {
            left.insert(path[0]);
        }
        
        for(auto &path: paths){
            if(left.find(path[1]) == left.end()) return path[1];
        }
        
        //  unreacheable code
        return "";
    }
};
