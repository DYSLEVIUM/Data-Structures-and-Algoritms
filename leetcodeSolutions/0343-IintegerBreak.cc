class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        else if(n == 3) return 2;

        // f = x * (n - x) -> after differentiation, x = n / 2 for maximum
        // if n is even -> n / 2 * n / 2 
        // else if n is odd -> (n - 1) / 2 * (n + 1) / 2;

        // also we will only break when n / 2 * n / 2 <= n
        // or (n - 1) / 2 * (n + 1) / 2 <= n
        // so n <= 4

        int prod = 1;
        while(n > 4) {
            prod *= 3;
            n -= 3;
        }

        return prod * n; // remaining of n
    }
};
