#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int numSubarraysWithSum(const vector<int> & nums, const int & goal) {
        auto slidingWindowAtMost = [&nums](const int & goal){
            int n = nums.size();

            int sum = 0, ans = 0;
            int le = 0, ri = 0;
            while(ri < n) {
                sum += nums[ri++];
                while(le < ri && sum > goal) {
                    sum -= nums[le++];
                }
                ans += ri - le;
            }

            return ans;
        };

        return slidingWindowAtMost(goal) - slidingWindowAtMost(goal - 1);
    }
};

class Solution1 {
public:
    int numSubarraysWithSum(const vector<int> & nums, const int & goal) {
        unordered_map<int, int> freq;

        int sum = 0, ans = 0;
        for(const int & num : nums) {
            sum += num;
            ans += sum == goal;

            ans += freq[sum - goal];

            ++freq[sum];
        }

        return ans;
    }
};
