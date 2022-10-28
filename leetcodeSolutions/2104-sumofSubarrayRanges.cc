class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            int minn = nums[i], maxx = nums[i];
            for(int j = i; j < n; ++j) {
                maxx = max(maxx, nums[j]), minn = min(minn, nums[j]);
                ans += maxx - minn;
            }
        }
        return ans;
    }
};
