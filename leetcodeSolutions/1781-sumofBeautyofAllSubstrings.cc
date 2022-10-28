class Solution {
public:
    int beautySum(string s) {
        static constexpr int CHAR_SET = 26;
        static constexpr int INF = 0x3f3f3f3f;
        int n = s.size();

        auto get_beauty = [&](const vector<int> & fa){
            int minn = INF, maxx = -INF;
            for(int i = 0; i < CHAR_SET; ++i) {
                if(!fa[i]) continue;
                maxx = max(maxx, fa[i]);
                minn = min(minn, fa[i]);
            }
            return maxx - minn;
        };

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            vector<int> fa(CHAR_SET);
            for(int j = i; j < n; ++j) {
                ++fa[s[j] - 'a'];
                ans += get_beauty(fa);
            }
        }
        return ans;
    }
};

// giving TLE
class Solution1 {
public:
    int beautySum(string s) {
        static constexpr int CHAR_SET = 26;
        static constexpr int INF = 0x3f3f3f3f;
        int n = s.size();
        
        vector<vector<int>> fa(n + 1, vector<int>(CHAR_SET));
        for(int i = 1; i < n + 1; ++i) {
            ++fa[i][s[i - 1] - 'a'];
            for(int j = 0; j < CHAR_SET; ++j) fa[i][j] += fa[i - 1][j];
        }

        int ans = 0;
        for(int i = 1; i < n + 1; ++i) {
            for(int j = i + 1; j < n + 1; ++j) {
                // get min and max
                int minn = INF, maxx = -INF;
                for(int k = 0; k < CHAR_SET; ++k) {
                    if(fa[j][k] - fa[i - 1][k]) minn = min(minn, fa[j][k] - fa[i - 1][k]); // don't want to consider characters with 0 frequency
                    maxx = max(maxx, fa[j][k] - fa[i - 1][k]);
                }
                ans += maxx - minn;
            }
        }

        return ans;
    }
};
