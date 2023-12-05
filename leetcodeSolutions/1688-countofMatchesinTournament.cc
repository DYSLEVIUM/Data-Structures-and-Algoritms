class Solution {
public:
    int numberOfMatches(int n) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int ans = 0;
        while(n != 1) {
            ans += n >> 1;
            n += n & 1;
            n >>= 1;
        }
        return ans;
    }
};
