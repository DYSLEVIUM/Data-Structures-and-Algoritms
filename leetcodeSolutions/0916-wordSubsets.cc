class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        const int CHAR_SET = 26;
        vector<int> mx_cnt(CHAR_SET);
        for(auto &w2 : words2) {
            vector<int> cnt(CHAR_SET);
            for(auto &ch: w2) {
                ++cnt[ch - 'a'];
                mx_cnt[ch - 'a'] = max(mx_cnt[ch - 'a'], cnt[ch - 'a']);
            }
        }
        
        vector<string> res;
        for(auto &w1: words1) {
            vector<int> cnt(CHAR_SET);
            for(auto &ch : w1) {
                ++cnt[ch - 'a'];
            }
            
            bool all_chars_come = true;
            for(int i = 0; i < CHAR_SET; ++i) {
                if(cnt[i] < mx_cnt[i]) {
                    all_chars_come = false;
                }
            }
            
            if(all_chars_come) {
                res.push_back(w1);
            }
        }
        
        return res;
    }
};
