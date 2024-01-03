class Solution {
public:
    int numSubarrayBoundedMax(const vector<int> & nums, const int & left, const int & right) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = nums.size();
        auto count = [&](const int & bound){
            int ans = 0, cnt = 0;
            for(const int & num : nums) {
                cnt += num <= bound ? cnt + 1 : 0;
                ans += cnt;
            }
            return ans;
        };

        return count(right) - count(left - 1);
    }
};
