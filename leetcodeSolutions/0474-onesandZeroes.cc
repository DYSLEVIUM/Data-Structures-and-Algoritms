class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        
        vector<pair<int, int>> fa(sz);
        for(int i = 0; i < sz; ++i) {
            int cnt_0 = count(strs[i].begin(), strs[i].end(), '0'), cnt_1 = count(strs[i].begin(), strs[i].end(), '1');
            fa[i] = {cnt_0, cnt_1};
        }
        
        auto cmp_0 = [](pair<int, int> &a, pair<int, int> &b){
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        };
        
        auto cmp_1 = [](pair<int, int> &a, pair<int, int> &b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        };
        
        auto cmp_01 = [](pair<int, int> &a, pair<int, int> &b){
            if(a.first + a.second == b.first + b.second) return a.first < b.first;
            return a.first + a.second < b.first + b.second;
        };
        
        auto get_ans = [&m, &n, &sz, &fa](){
            int ans = 0;
            int total_m = 0, total_n = 0;
            for(int i = 0; i < sz; ++i) {
                auto &[cnt_0, cnt_1] = fa[i];
                if(total_m + cnt_0 <= m && total_n + cnt_1 <= n) {
                    ++ans;
                    total_m += cnt_0;
                    total_n += cnt_1;
                }
            }
            
            return ans;
        };
        
        sort(fa.begin(), fa.end(), cmp_0);
        int a1 = get_ans();
        
        sort(fa.begin(), fa.end(), cmp_1);
        int a2 = get_ans();
        
        sort(fa.begin(), fa.end(), cmp_01);
        int a3 = get_ans();
        
        return max({a1, a2, a3});
        
        //  dp solution
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
//         for(auto &str: strs) {
//             int cnt_0 = count(str.begin(), str.end(), '0'), cnt_1 = count(str.begin(), str.end(), '1');
            
//             //  going from bottom-left as we don't want the future interation in this string to use the updated values (which have been updated in the current iteration)
//             for(int i = m; i >= cnt_0; --i) {
//                 for(int j = n; j >= cnt_1; --j) {
//                     dp[i][j] = max(dp[i][j], 1 + dp[i - cnt_0][j - cnt_1]);
//                 }
//             }
//         }
        
//         return dp[m][n];
    }
};
