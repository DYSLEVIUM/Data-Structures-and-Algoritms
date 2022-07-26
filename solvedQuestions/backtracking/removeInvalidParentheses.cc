class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        
        int best_removed = n;
        unordered_set<string> valid_str;
        auto solve = [&](const auto &solve, const int &idx, const string &curr_str, const int &curr_removed, int open_cnt, int close_cnt){
            if(curr_removed > best_removed || close_cnt > open_cnt) {
                return;
            }

            if(idx == n) {
                if(open_cnt != close_cnt) {
                    return;
                }
                
                best_removed = min(best_removed, n - (int)curr_str.length());
                valid_str.insert(curr_str);
                return;
            }
            
            if(s[idx] == '(' || s[idx] == ')') {
                solve(solve, idx + 1, curr_str, curr_removed + 1, open_cnt, close_cnt);
            }
            
            if(s[idx] == '(') {
                ++open_cnt;
            }
            
            if(s[idx] == ')') {
                ++close_cnt;
            }
            
            solve(solve, idx + 1, curr_str + s[idx], curr_removed, open_cnt, close_cnt);
        };
        solve(solve, 0, "", 0, 0, 0);
        
        vector<string> ans;
        for(auto &ss: valid_str) {
            if(ss.length() + best_removed == n) {
                ans.push_back(ss);
            }
        }
        
        return ans;
    }
};
