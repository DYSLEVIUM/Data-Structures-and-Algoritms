class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            int j = i;
            while(!nums[i] && j < n && !nums[j]) {
                ++j;
            }

            long long len = j - i;
            ans += (len * (len + 1)) / 2;

            i = j;
        }

        return ans;
    }
};
