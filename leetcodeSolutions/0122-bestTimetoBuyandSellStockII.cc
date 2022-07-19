class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
//         vector<vector<int>> dp(n, vector<int>(2, -1));
//         auto recur = [&](const auto &recur, const int &idx, const bool &is_holding){
//             if(idx == n) {
//                 return 0;
//             }
            
//             if(dp[idx][is_holding] != -1) {
//                 return dp[idx][is_holding];
//             }
            
//             int profit = 0;
//             if(is_holding) {
//                 profit = max(prices[idx] + recur(recur, idx + 1, false),    //  selling 
//                              recur(recur, idx + 1, true)
//                             );
//             } else {
//                 profit = max(-prices[idx] + recur(recur, idx + 1, true),    //  buying
//                              recur(recur, idx + 1, false)
//                             );
//             }
            
//             return dp[idx][is_holding] = profit;
//         };
        
//         return recur(recur, 0, false);
    
        vector<vector<int>> dp(n, vector<int>(2));
        for(int i = 1; i < n; ++i) {
            for(int is_holding = 0; is_holding < 2; ++is_holding) {
                int profit = 0;
                if(is_holding) {
                    profit = max(prices[i] + dp[i - 1][0],    //  selling 
                                dp[i - 1][1]);
                } else {
                    profit = max(-prices[i] + dp[i - 1][1],    //  buying
                                dp[i - 1][0]);
                }
                dp[i][is_holding] = profit;
            }
        }
        
        return dp[n - 1][1];
    }
};
