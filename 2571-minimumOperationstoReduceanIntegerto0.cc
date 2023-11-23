class Solution {
public:
    int minOperations(int n) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int ans = 0;
        while(n) {
            if((n & 3) == 3) { // if we have continuous 1, we convert to single 1 in bit by adding 1
                ++n, ++ans;
            } else {
                ans += n & 1; // if we need to remove the last bit
                n >>= 1;
            }
        }

        return ans;
    }
};
