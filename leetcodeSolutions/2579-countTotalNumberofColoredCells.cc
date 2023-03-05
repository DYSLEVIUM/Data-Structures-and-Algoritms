class Solution {
public:
    long long coloredCells(int n) {
        // https://leetcode.com/problems/count-total-number-of-colored-cells/solutions/3256196/java-c-python-cut-and-combine-o-1/?orderBy=most_votes
        --n;
        long long ans = 1LL * 2 * n * (n + 1) + 1;
        return ans;
    }
};
