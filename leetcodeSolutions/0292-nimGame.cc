class Solution {
public:
    bool canWinNim(int n) {
        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // auto recur = [&dp](const auto & recur, const int &n, const int & is_my_turn){
        //     if(n <= 3) return is_my_turn;

        //     if(dp[n][is_my_turn] != -1) return dp[n][is_my_turn];

        //     bool can_win = false;
        //     for(int i = 1; i <= 3; ++i) can_win |= recur(recur, n - i, !is_my_turn);
            
        //     return dp[n][is_my_turn] = !!can_win;
        // };
        // return recur(recur, n, 1);

        // winning states: 1, 2, 3, 5, 6, 7, ...
        // losing states: 4, 8, ...
        // return (n % 4);

        // generally
        int maxx_choice = 3;
        return (n % (maxx_choice + 1));
    }
};
