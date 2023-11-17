class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        cin.tie(0)->sync_with_stdio(false);

        int n = nums.size();

        // kadane's algorithm
        int ans = 0, maxx = 0, minn = 0;
        for(int i = 0; i < n; ++i) {
            maxx = max(nums[i], nums[i] + maxx);
            minn = min(nums[i], nums[i] + minn);
            ans = max({ans, abs(maxx), abs(minn)});
        }

        return ans;
    }
};
