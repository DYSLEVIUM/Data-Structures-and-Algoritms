class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        using VI = vector<int>;
        
//         int transactions = 2;
//         vector<vector<VI>> dp(n, vector<VI>(2, VI(transactions + 1, -1)));
//         auto recur = [&](const auto &recur, const int &idx, const bool &is_holding, const int &transactions_left){
//             if(idx == n || !transactions_left) {
//                 return 0;
//             }
            
//             if(dp[idx][is_holding][transactions_left] != -1) {
//                 return dp[idx][is_holding][transactions_left];
//             }
            
//             int profit = 0;
//             if(is_holding) {
//                 profit = max(prices[idx] + recur(recur, idx + 1, false, transactions_left - 1), 
//                             recur(recur, idx + 1, true, transactions_left));
//             } else {
//                 profit = max(-prices[idx] + recur(recur, idx + 1, true, transactions_left),
//                             recur(recur, idx + 1, false, transactions_left));
//             }
            
//             return dp[idx][is_holding][transactions_left] = profit;
//         };
//         return recur(recur, 0, 0, transactions);
        
        int transactions = 2;
        vector<vector<VI>> dp(n + 1, vector<VI>(2, VI(transactions + 1)));
        for(int i = n - 1; i >= 0; --i) {
            for(int is_holding = 0; is_holding < 2; ++is_holding) {
                for(int k = 0; k < transactions + 1; ++k) {
                    if(!k) {
                        dp[i][is_holding][k] = 0;
                        continue;
                    }
                    
                    int profit = 0;
                    if(is_holding) {
                        profit = max(prices[i] + dp[i + 1][0][k - 1], dp[i + 1][1][k]);
                    } else {
                        profit = max(-prices[i] + dp[i + 1][1][k], dp[i + 1][0][k]);
                    }
                    
                    dp[i][is_holding][k] = profit;
                }
            }
        }
        
        return dp[0][0][2];
    }
};
