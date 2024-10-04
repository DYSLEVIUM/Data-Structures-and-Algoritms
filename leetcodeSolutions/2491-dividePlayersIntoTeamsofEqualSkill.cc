#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    long long dividePlayers(vector<int> & skill) {
        int n = skill.size();

        int teams = n >> 1;

        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += skill[i];
        }

        int target = sum / teams;
        if(sum != target * teams) {
            return -1;
        }

        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            ++mp[skill[i]];
        }

        long long chemistry = 0;
        for(int i = 0; i < n; ++i) {
            int need = target - skill[i];
            if(--mp[need] < 0) {
                return -1;
            }
            
            chemistry += 1LL * skill[i] * need;
        }

        return chemistry >> 1;
    }
};
