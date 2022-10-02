class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        constexpr int MOD = 1e9 + 7;
        static_assert(MOD == 1e9 + 7);

        vector<int> prev(target + 1);
        prev[0] = 1;
        for(int i = 1; i < n + 1; ++i) {
            vector<int> curr(target + 1);
            for(int j = 1; j < target + 1; ++j) {
                for(int kk = 1; kk <= k; ++kk) {
                    if(j - kk >= 0) {
                        curr[j] = curr[j] + prev[j - kk];
                        curr[j] %= MOD;
                    }
                }
            }
            prev = curr;
        }

        return prev[target]; 
    }
};
