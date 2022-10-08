class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int ans = 0;
        while(left <= right) {
            int cnt = __builtin_popcount(left++);
            ans += primes.count(cnt);
        }

        return ans;
    }
};
