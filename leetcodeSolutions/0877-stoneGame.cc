class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // we can actually deduce that alice will always win according to the given constraints
        return true;

        // int n = piles.size();

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // auto recur = [&](const auto &recur, const int &lo, const int &hi){
        //     if(lo > hi) return 0;

        //     if(dp[lo][hi] != -1) return dp[lo][hi];
            
        //     // min-max algorithm from AI (can be pruned using alpha-beta pruning)
        //     int op1 = piles[lo] + min(piles[lo + 1] + recur(recur, lo + 2, hi),
        //                                 piles[hi - 1] + recur(recur, lo + 1, hi - 1));
        //     int op2 = piles[hi] + min(piles[lo + 1] + recur(recur, lo + 1, hi - 1),
        //                                 piles[hi - 1] + recur(recur, lo, hi - 2));

        //     return dp[lo][hi] = max(op1, op2);
        // };

        // int sum = accumulate(piles.begin(), piles.end(), 0);
        // int alice_sum = recur(recur, 0, n - 1);
        // int bob_sum = sum - alice_sum;

        // return alice_sum > bob_sum;
    }
};
