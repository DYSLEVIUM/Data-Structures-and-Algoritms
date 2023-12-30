class Solution {
public:
    bool makeEqual(const vector<string> & words) {
        cin.tie(nullptr)->sync_with_stdio(false);

        constinit static const int CHAR_SET = 26;
        
        int n = words.size();

        int fa[CHAR_SET]{};
        for(const string & word : words) {
            for(const char & ch : word) {
                ++fa[ch - 'a'];
            }
        }

        for(int i = 0; i < CHAR_SET; ++i) {
            if(fa[i] % n) {
                return false;
            }
        }
        return true;
    }
};
