#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    bool checkValidString(const string & s) {
        const int n = s.size();
        
        int open = 0, close = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(' || s[i] == '*') {
                ++open;
            } else {
                --open;
            }

            if(s[n - 1 - i] == ')' || s[n - 1 - i] == '*') {
                ++close;
            } else {
                --close;
            }

            if(open < 0 || close < 0) {
                return false;
            }
        }

        return true;
    }
};
