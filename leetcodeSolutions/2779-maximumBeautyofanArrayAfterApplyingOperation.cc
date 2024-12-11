#pragma GCC optimize("O3", "unroll_loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        static constinit const int INF = 0x3f3f3f3f;
        
        const int n = nums.size();

        vector<pair<int, int>> events(2 * n);
        for(int i = 0; const int & num : nums) {
            events[i++] = {num - k, 1};
            events[i++] = {num + k + 1, -1};
        }
        sort(events.begin(), events.end());

        int maxx = -INF;
        int cnt = 0;
        for(const auto & [_, effect]: events) {
            cnt += effect;
            maxx = max(maxx, cnt);
        }

        return maxx;
    }
};
