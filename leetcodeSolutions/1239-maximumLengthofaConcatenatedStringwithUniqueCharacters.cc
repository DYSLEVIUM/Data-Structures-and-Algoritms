class Solution {
public:
    int maxLength(vector<string>& arr) {
        unordered_map<int, unordered_map<int, int>> dp;
        auto dfs = [&](const auto & dfs, const int & idx, const int & mask){
            if(idx == arr.size()) return 0;

            if(dp.count(idx) && dp[idx].count(mask)) return dp[idx][mask];

            int not_take_mask = mask;
            int take_mask = mask;

            for(auto & ch : arr[idx]) {
                if(mask >> (ch - 'a') & 1) return dfs(dfs, idx + 1, not_take_mask);
                take_mask |= 1 << (ch - 'a');
            }

            return dp[idx][mask] = max(dfs(dfs, idx + 1, not_take_mask), dfs(dfs, idx + 1, take_mask) + (int) arr[idx].size());
        };
        return dfs(dfs, 0, 0);
    }
};
