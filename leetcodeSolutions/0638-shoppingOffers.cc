#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int shoppingOffers(vector<int> & price, vector<vector<int>> & special, vector<int> & needs) {
        static const int INF = 0x3f3f3f3f;
        static const int ENCODING_SIZE = 4; // max value of element in needs is 10, closest power of 2 is 16 -> 4; and the total elements is 6, so for every 4 bit we store how many element of a specific need is used as state

        int n = price.size();

        for(int i = 0; i < n; ++i) {
            vector<int> curr(n + 1);

            curr[i] = 1;
            curr[n] = price[i];

            special.push_back(curr);
        }

        int ns = special.size();

        int total_needs = accumulate(needs.begin(), needs.end(), 0);

        vector<unordered_map<int, int>> dp(ns);
        
        // make bitmask of how many items used from needs, and take that as state for dp
        // remaining_needs is not a state, as it is a function of mask itself
        auto recur = [&](
            const auto & recur,
            const int & remaining_needs,
            const int & idx = 0,
            const int & mask = 0
        ){
            if(idx == ns) {
                return INF;
            }

            if(dp[idx].count(mask)) {
                return dp[idx][mask];
            }

            if(!remaining_needs) {
                return dp[idx][mask] = 0;
            }

            auto not_take = recur(recur, remaining_needs, idx + 1, mask);

            bool valid_mask = true;
            int temp_mask = mask, new_mask = 0, added_needs = 0;
            for(int i = 0; i < n; ++i) {
                int curr_need = temp_mask & ((1 << ENCODING_SIZE) - 1);
                temp_mask >>= ENCODING_SIZE;

                int new_need = curr_need + special[idx][n - 1 - i];
                if(new_need > needs[n - 1 - i]) { // if after taking taking this offer, we cross the threshold, it becomes invalid and can invalidate this subtree of calls
                    valid_mask = false;
                    break;
                }

                new_mask |= new_need << (ENCODING_SIZE * i);
                added_needs += special[idx][n - 1 - i];
            }

            auto take = !valid_mask ? INF :
                special[idx][n] + recur(recur, remaining_needs - added_needs, idx, new_mask);

            return dp[idx][mask] = min(take, not_take);
        };

        return recur(recur, total_needs);
    }
};
