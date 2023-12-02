class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        cin.tie(nullptr)->sync_with_stdio(false);

        constinit static const int CHAR_SET = 26; 

        int fa[CHAR_SET]{};
        for(const char & ch : chars) {
            ++fa[ch - 'a'];
        }

        int ans = 0;
        for(const string & word: words) {
            int te[CHAR_SET]{};
            for(const char & ch: word) {
                ++te[ch - 'a'];
            }

            bool ok = true;
            for(int i = 0; i < CHAR_SET; ++i) {
                ok &= fa[i] >= te[i];
            }

            ans += ok * word.size();
        }

        return ans;
    }
};
