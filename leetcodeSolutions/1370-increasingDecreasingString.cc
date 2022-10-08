class Solution {
public:
    string sortString(string s) {
        constexpr int CHAR_SET = 26;
        static_assert(CHAR_SET == 26);

        int fa[CHAR_SET] = {};
        for(auto &ch : s) {
            ++fa[ch - 'a'];
        }

        string ans;
        while(s.size() != ans.size()) {
            for(int i = 0; i < CHAR_SET; ++i) {
                ans += string(--fa[i] >= 0 ? 1 : 0, 'a' + i);
            }

            for(int i = CHAR_SET - 1; i >= 0; --i) {
                ans += string(--fa[i] >= 0 ? 1 : 0, 'a' + i);
            }
        }

        return ans;
    }
};
