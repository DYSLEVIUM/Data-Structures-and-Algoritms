class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);

        int ans = 0;
        // making the MSB's 0
        for(int i = 31; i >= 0; --i) {
            int mask = 1 << i;
            if((num1 & mask) && cnt) {
                ans |= mask;
                --cnt;
            }
        }

        // filling extra 1's from the back to minimize xor
        for(int i = 0; i <= 31; ++i) {
            int mask = 1 << i;
            if((ans & mask) == 0 && cnt) {
                ans |= mask;
                --cnt;
            }
        }

        return ans;
    }
};
