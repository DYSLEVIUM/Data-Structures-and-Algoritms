class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        static constexpr int CHAR_SET = 26;

        vector<int> fa(CHAR_SET);
        for(char & ch : p) ++fa[ch - 'a'];
    
        int win_size = p.size();

        vector<int> curr(CHAR_SET);
        for(int i = 0; i < min((int)s.size(), win_size - 1); ++i) ++curr[s[i] - 'a'];

        vector<int> ans;
        for(int i = win_size - 1; i < s.size(); ++i) {
            ++curr[s[i] - 'a'];
            for(int j = 0; j < CHAR_SET; ++j) {
                if(fa[j] != curr[j]) break;
                if(j == CHAR_SET - 1) ans.push_back(i - win_size + 1);
            }
            --curr[s[i - win_size + 1] - 'a'];
        }
        return ans;
    }
};
