class Solution {
public:
    int arrangeCoins(int n) {
      return (-1 + 2 * sqrt(2 * ((long long)n + 1))) / 2;
    }
};
