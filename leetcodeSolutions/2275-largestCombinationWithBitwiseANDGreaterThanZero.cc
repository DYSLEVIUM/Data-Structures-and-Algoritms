class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        constexpr static int BITS = 32;
        
        int maxx = INT_MIN;
        for(int i = 0; i < BITS; ++i) {
            int cnt = 0, mask = (1 << i);
            for(auto &candidate : candidates) {
                cnt += mask & candidate ? 1 : 0;
            }
            maxx = max(maxx, cnt);
        }

        return maxx;
    }
};
