#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int minMoves(vector<int> & nums) {
        // sum + m * (n - 1) = x * n; x = minNum + m; minimum number will always be minimum and will require m moves to become equal

        int n = nums.size();

        int sum = 0, minn = 0x3f3f3f3f;
        for(int & num: nums) {
            sum += num;
            minn = min(minn, num);
        }

        return sum - minn * n;
    }
};
