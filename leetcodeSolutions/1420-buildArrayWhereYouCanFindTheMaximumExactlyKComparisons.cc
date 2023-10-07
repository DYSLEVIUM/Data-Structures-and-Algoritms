// https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/solutions/586576/c-bottom-up-dynamic-programming-with-explanation/
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        long long ways[51][101][51]{};
        constinit static long MOD = 1e9 + 7;

        // 1 element and score is 1
        for (int b = 1; b <= m; ++b) {
            ways[1][b][1] = 1;
        }

        for (int a = 1; a <= n; ++a) {
            for(int b = 1; b <= m; ++b) {
                for(int c = 1; c <= k; ++c) {
                    long long sum = 0;

                    // case1: we can append any element from [1, b] to the end of the array
                    sum = (b * ways[a - 1][b][c]) % MOD;

                    // case2: we can append the element "b" to the end of the array
                    for (int x = 1; x < b; ++x) {
                        sum = (sum + ways[a - 1][x][c - 1]) % MOD;
                    }

                    ways[a][b][c] = (sum + ways[a][b][c]) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int j = 1; j <= m; ++j) {
            ans = (ans + ways[n][j][k]) % MOD;
        }

        return ans;
    }
};
