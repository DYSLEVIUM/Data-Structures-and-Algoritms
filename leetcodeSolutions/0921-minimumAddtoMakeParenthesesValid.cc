#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int minAddToMakeValid(string & s) {
        int open = 0, cnt = 0;
        for(auto & ch : s) {
            if(ch == '(') {
                ++open;
                continue;
            }
            
            if(open) {
                --open;
            } else {
                ++cnt;
            }
        }

        return open + cnt;
    }
};
