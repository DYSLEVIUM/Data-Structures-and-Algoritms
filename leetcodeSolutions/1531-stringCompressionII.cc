class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        static constexpr int INF = 0x3f3f3f3f;
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        auto recur = [&](const auto &recur, const int &idx, const int &curr_k) -> int {
            if(curr_k < 0){
                return INF;
            }
   
            if(idx >= n or n - idx <= curr_k) {
                return 0;
            }

            if(dp[idx][curr_k] != -1) {
                return dp[idx][curr_k];
            }
            
            int cnt[26] = {}, maxx = 0, res = INF;
            for(int i = idx; i < n; ++i) {
                // we greedily remove the less repeated characters, one by one that is
                maxx = max(maxx, ++cnt[s[i] - 'a']);
                int len = maxx == 1 ? 0 : to_string(maxx).size();
                res = min(res, 1 + len + recur(recur, i + 1, curr_k - (i - idx + 1 - maxx)));
            }

            return dp[idx][curr_k] = res;
        };

        return recur(recur, 0, k);
    }
};
