
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        auto sum = [](long long n){
            long long res = 0;
            while(n) {
                res += n % 10;
                n /= 10;
            }
            return res;
        };
      
        long long temp = n, base = 1;
        while (sum(n) > target) {
            n = n / 10 + 1;
            base *= 10;
        }
        return n * base - temp;
    }
};
