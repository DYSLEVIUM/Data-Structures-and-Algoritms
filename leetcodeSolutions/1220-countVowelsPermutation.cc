class Solution {
public:
    int countVowelPermutation(int n) {
        constexpr int MOD = 1e9 + 7;
        
//         unordered_map<char, vector<char>> mp;
//         mp[' '] = { 'a', 'e', 'i', 'o', 'u'};
//         mp['a'] = { 'e' };
//         mp['e'] = { 'a', 'i' };
//         mp['i'] = { 'a', 'e', 'o', 'u'};
//         mp['o'] = { 'i', 'u' };
//         mp['u'] = { 'a' };
        
//         using UCI = unordered_map<char, int>;
//         unordered_map<int, UCI> dp;
//         auto recur = [&](const auto &recur, const int &n, const char &last_ch){
//             if(!n) {
//                 return 1;
//             }
            
//             if(dp.find(n) != dp.end() && dp[n].find(last_ch) != dp[n].end()) {
//                 return dp[n][last_ch];
//             }

//             int new_n = n - 1, cnt = 0;
//             for(auto &ch : mp[last_ch]) {
//                 cnt += recur(recur, new_n, ch);
//                 cnt %= MOD;
//             }
            
//             return dp[n][last_ch] = cnt;
//         };
//         return recur(recur, n, ' ');
        
        constexpr int v_s = 5;
        vector<vector<int>> valid_prev = {{1, 2, 4}, {0, 2}, {1, 3}, {2}, {2, 3}}; // current vowel can be made which other vowels
        
//         vector<vector<int>> dp(n, vector<int>(v_s, 1)); // stores a, e, i, o, u count
//         for(int i = 1; i < n; ++i) {
//             for(int j = 0; j < v_s; ++j) {
//                 dp[i][j] = 0;
//                 for(auto &mappings : valid_prev[j]) {
//                     dp[i][j] += dp[i - 1][mappings];
//                     dp[i][j] %= MOD;
//                 }
//             }
//         }
        
//         int ans = 0;
//         for(auto &num : dp.back()) {
//             ans += num;
//             ans %= MOD;
//         }
        
//         return ans;
        
        vector<int> prev(v_s, 1);
        for(int i = 1; i < n; ++i) {
            vector<int> curr(v_s);
            for(int j = 0; j < v_s; ++j) {
                for(auto &mappings : valid_prev[j]) {
                    curr[j] += prev[mappings];
                    curr[j] %= MOD;
                }
            }
            prev = curr;
        }
        
        int ans = 0;
        for(auto &num : prev) {
            ans += num;
            ans %= MOD;
        }
        
        return ans;
    }
};
