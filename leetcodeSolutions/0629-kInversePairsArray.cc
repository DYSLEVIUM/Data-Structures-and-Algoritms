class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        
//         vector<vector<int>> cache(n + 1, vector<int>(k + 1, -1));
//         auto recur = [&MOD, &cache](const auto &recur, const int &n, const int &k){
//             if(n == 0) {
//                 return cache[n][k] = 0;
//             }
            
//             //  only the sorted array is possible
//             if(k == 0) {
//                 return cache[n][k] = 1;
//             }
            
//             if(cache[n][k] != -1) {
//                 return cache[n][k];
//             }
            
//             int inv = 0;
//             for(int i = 0; i <= min(k, n - 1); ++i) {
//                 //  put the nth element at (n - i) position, adding i inversions
//                 inv = (inv + recur(recur, n - 1, k - i)) % MOD;
//             }
            
//             return cache[n][k] = inv;
//         };
//         recur(recur, n, k);
        
//         return cache[n][k];
        
//         vector<vector<int>> cache(n + 1, vector<int>(k + 1));
//         for(int i = 1; i < n + 1; ++i) {
//             for(int j = 0; j < k + 1; ++j) {
//                 if(!j){
//                     cache[i][j] = 1;
//                     continue;
//                 }
                
//                 for(int l = 0; l <= min(i - 1, j); ++l) {
//                     cache[i][j] = (cache[i][j] + cache[i - 1][j - l]) % MOD;
//                 }
//             }
//         }
        
//         return cache[n][k];
                
        //  can be made O(n) space
        vector<vector<int>> cache(n + 1, vector<int>(k + 1));
        for(int i = 1; i < n + 1; ++i) {
            for(int j = 0; j < k + 1; ++j) {
                if(!j){
                    cache[i][j] = 1;
                    continue;
                }

                //  we are now storing the cumulative sum till current column in each row
                int val = (cache[i - 1][j] - (j - i >= 0 ? cache[i - 1][j - i] : 0) + MOD) % MOD;
                cache[i][j] = (val + cache[i][j - 1]) % MOD;
            }
        }
        
        return (cache[n][k] - (k > 0 ? cache[n][k - 1] : 0) + MOD) % MOD;
    }
};
