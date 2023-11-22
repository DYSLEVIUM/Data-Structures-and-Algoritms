// class Solution {
// public:
//     bool pyramidTransition(string bottom, vector<string>& allowed) {
//         cin.tie(nullptr)->sync_with_stdio(false);
        
//         unordered_map<string, vector<char>> mp;
//         for(const string & str: allowed) {
//             mp[str.substr(0, 2)].push_back(str[2]);
//         }

//         auto dfs = [&mp](const auto & dfs, const string & prev) -> bool {
//             if(prev.size() == 1) {
//                 return true;
//             }

//             auto generate_valid = [&](const auto & generate_valid, const int & i, const string & valid) -> bool {
//                 if(i == prev.size() - 1) {
//                     return dfs(dfs, valid);
//                 }

//                 for(const char & c: mp[prev.substr(i, 2)]) {
//                     if(generate_valid(generate_valid, i + 1, valid + c)) {
//                         return true;
//                     }
//                 }

//                 return false;
//             };

//             return generate_valid(generate_valid, 0, "");
//         };

//         return dfs(dfs, bottom);
//     }
// };

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        cin.tie(nullptr)->sync_with_stdio(false);
        
        unordered_map<string, vector<char>> mp;
        for(const string & str: allowed) {
            mp[str.substr(0, 2)].push_back(str[2]);
        }

        auto dfs = [&mp](const auto & dfs, const string & bottom, const int & st, const string & next) -> bool {
            if(bottom.size() == 1) {
                return true;
            }

            if(st == bottom.size() - 1) {
                return dfs(dfs, next, 0, "");
            }

            for(const char & ch: mp[bottom.substr(st, 2)]) {
                if(dfs(dfs, bottom, st + 1, next + ch)) {
                    return true;
                }
            }

            return false;
        };

        return dfs(dfs, bottom, 0, "");
    }
};
