#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int minimizeXor(const int & num1, const int & num2) {
        static constinit const int BITS = 31;

        int cnt = __builtin_popcount(num2);
    
        int ans = 0;

        // start making 0 for ans based on num1
        for(int i = BITS; i >= 0; --i) {
            int mask = 1 << i;
            if((num1 & mask) && cnt) {
                ans |= mask;
                --cnt;
            }
        }

        // rest of the 1's are going from first if available
        for(int i = 0; i <= BITS; ++i) {
            int mask = 1 << i;
            if(!(ans & mask) && cnt) {
                ans |= mask;
                --cnt; 
            }
        }

        return ans;
    }
};
