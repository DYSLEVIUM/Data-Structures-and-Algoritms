#pragma GCC("03", "optimize-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int n = boxes.size();

        vector<int> ans(n, 0);
        int sum = boxes[0] - '0';

        for(int i = 1; i < n; ++i) {
            ans[i] += ans[i - 1] + sum;
            sum += boxes[i] - '0';
        }

        int prev = 0; // ans already has for prefix; so we get another variable to track the suffix cost
        sum = boxes[n - 1] - '0';
        for(int i = n - 2; i >= 0; --i) {
            prev += sum;
            ans[i] += prev;
            sum += boxes[i] - '0'; 
        }

        return ans;
    }
};
