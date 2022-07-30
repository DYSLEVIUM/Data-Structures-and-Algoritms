class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        const int CHAR_SET = 26;
        int *mx_cnt = new int[CHAR_SET]{ 0 };
        for(auto &w2 : words2) {
            int *cnt = new int[CHAR_SET]{ 0 };
            for(auto &ch: w2) {
                ++cnt[ch - 'a'];
                mx_cnt[ch - 'a'] = max(mx_cnt[ch - 'a'], cnt[ch - 'a']);
            }
        }
        
        vector<string> res;
        for(auto &w1: words1) {
            int *cnt = new int[CHAR_SET]{ 0 };
            for(auto &ch : w1) {
                ++cnt[ch - 'a'];
            }
            
            bool all_char_comes = true;
            for(int i = 0; i < CHAR_SET; ++i) {
                if(cnt[i] < mx_cnt[i]) {
                    all_char_comes = false;
                }
            }
            
            if(all_char_comes) {
                res.push_back(w1);
            }
        }
        
        return res;
    }
};
