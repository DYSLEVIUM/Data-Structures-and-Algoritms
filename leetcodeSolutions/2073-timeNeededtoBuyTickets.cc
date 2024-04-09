#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int timeRequiredToBuy(const vector<int> & tickets, const int & k) {
        const int n = tickets.size();

        int time = 0;
        for(int i = 0; i < n; ++i) {
            if(i <= k) {
                time += min(tickets[k], tickets[i]);
            } else {
                time += min(tickets[k] - 1, tickets[i]);
            }
        }

        return time;
    }
};
