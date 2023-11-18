class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<long> pre(n);
        pre[0] = nums[0];

        int ans = 1;
        for(int i = 1; i < n; ++i) {
            pre[i] += nums[i] + pre[i - 1];

            int target = nums[i];
            int left = 0, right = i;
            while(left < right) {
                int mid = left + ((right - left) >> 1);

                long cnt = i - mid + 1;
                long final_sum = cnt * target;
                int original_sum = pre[i] - pre[mid] + nums[mid];
                int req = final_sum - original_sum;

                if(req > k) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            ans = max(ans, i - right + 1);
        }

        return ans;
    }
};
