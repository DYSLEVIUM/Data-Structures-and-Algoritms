class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int maxx = -0x3f3f3f;
        for(int i = 0; i < n / 2; ++i) {
            maxx = max(maxx, nums[i] + nums[n - 1 - i]);
        }

        return maxx;
    }
};
