class Solution {
public:
    int percentageLetter(string s, char letter) {
        constexpr int CHAR_SET = 26;
        static_assert(CHAR_SET == 26);

        int fa[CHAR_SET] = {};
        for(auto &ch : s) {
            ++fa[ch - 'a'];
        }

        return fa[letter - 'a'] * 100 / s.size();
    }
};
