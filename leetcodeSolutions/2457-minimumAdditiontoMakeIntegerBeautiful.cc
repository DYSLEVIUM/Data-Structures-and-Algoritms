
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
      
        // greedily choose the back digits to become 0
        long long temp = n, base = 1;
        while (sum(n) > target) {
            n = n / 10 + 1; // 1 is the forwarded carry to previous digit, i.e., after adding that digit, we make it 0, so the digit just on the left will increment by 1
            base *= 10;
        }
        return n * base - temp;
    }
};
