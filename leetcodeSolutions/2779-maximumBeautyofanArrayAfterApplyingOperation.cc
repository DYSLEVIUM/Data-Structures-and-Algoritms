#pragma GCC optimize("O3", "unroll_loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution1 {
public:
    int maximumBeauty(vector<int>& nums, const int & k) {
        static constinit const int INF = 0x3f3f3f3f;
        
        const int n = nums.size();

        vector<pair<int, int>> events(2 * n);
        for(int i = 0; const int & num : nums) {
            events[i++] = {num - k, 1};
            events[i++] = {num + k + 1, -1};
        }
        sort(events.begin(), events.end());

        int cnt = 0;
        int maxx = -INF;
        for(const auto & [_, effect]: events) {
            cnt += effect;
            maxx = max(maxx, cnt);
        }

        return maxx;
    }
};

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        static constinit const int INF = 0x3f3f3f3f;
        static constinit const int MAX_N = 1e5;
        
        int maxx = -INF;

        array<int, MAX_N + 1> st{}, ed{};
        for(const int & num: nums) {
            int le = num - k; 
            int ri = num + 1 + k;

            ++st[max(0, le)];

            if(ri < MAX_N + 1) {
                ++ed[ri];
            }
            
            maxx = max(maxx, num);
        }

        int sum = 0;
        int cnt = -INF;
        for(int i = 0; i < maxx + 1; ++i) {
            sum += st[i] - ed[i];
            cnt = max(cnt, sum);
        }

        return cnt;
    }
};
