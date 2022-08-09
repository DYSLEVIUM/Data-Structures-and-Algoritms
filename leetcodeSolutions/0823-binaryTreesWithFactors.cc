class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        
//         unordered_set<int> allowed;
//         for(auto &num : arr) {
//             allowed.insert(num);
//         }
        
//         unordered_map<int, int> cache;
//         auto recur = [&](const auto &recur, const int &node) -> int {
//             if(cache.count(node)) {
//                 return cache[node];
//             }
            
//             long long curr_total = 1;
//             for(auto &num : arr) {
//                 if(node % num == 0 && allowed.count(node / num)) {
//                     curr_total += 1LL * recur(recur, node / num) * recur(recur, num);
//                     curr_total %= MOD;
//                 }
//             }
            
//             return cache[node] = curr_total;
//         };
        
//         int total = 0;
//         for(auto &num: arr) {
//             total += recur(recur, num);
//             total %= MOD;
//         }
        
//         return total;
        
        int n = arr.size();
        
        // sorting as, we we are doing bottom-up
        sort(arr.begin(), arr.end());
        
        unordered_map<int, int> allowed;
        for(int i = 0; i < n; ++i) {
            allowed[arr[i]] = i;
        }
        
        vector<long long> dp(n, 1);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(arr[i] % arr[j] == 0) {
                    int rest = arr[i] / arr[j];
                    if(allowed.count(rest)) {
                        dp[i] += dp[j] * dp[allowed[rest]];
                        dp[i] %= MOD;
                    }
                }
            }
        }
        
        long ans = 0;
        for(auto &num : dp) {
            ans += num;
        }
        
        return ans % MOD;
    }
};
