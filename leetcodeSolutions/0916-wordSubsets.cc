#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    vector<string> wordSubsets(const vector<string> & words1, const vector<string> & words2) {
        static constinit const int CHAR_SET = 26;

        array<int, CHAR_SET> mx_cnt{};
        for(const auto & w2 : words2) {
            array<int, CHAR_SET> cnt{};
            for(const auto & ch: w2) {
                mx_cnt[ch - 'a'] = max(mx_cnt[ch - 'a'], ++cnt[ch - 'a']);
            }
        }
        
        vector<string> res;
        for(const auto & w1: words1) {
            array<int, CHAR_SET> cnt{};
            for(const auto &ch : w1) {
                ++cnt[ch - 'a'];
            }
            
            bool all_char_comes = true;
            for(int i = 0; i < CHAR_SET; ++i) {
                if(cnt[i] < mx_cnt[i]) {
                    all_char_comes = false;
                    break;
                }
            }
            
            if(!all_char_comes) {
                continue;
            }
            
            res.push_back(w1);
        }
        
        return res;
    }
};
