class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        long long ans = 0, j = 0, j_min = -1, j_max = -1;
        for(int i = 0; i < n; ++i) {
            if(nums[i] < minK || nums[i] > maxK) {
                j_min = j_max = -1;
                j = i + 1;
            }

            if(nums[i] == minK) {
                j_min = i;
            }

            if(nums[i] == maxK) {
                j_max = i;
            }

            // the starting element of the subarray can be choosen in the interval [j, ]min(j_min, j_max)]
            ans += max(0LL, min(j_min, j_max) - j + 1);
        }

        return ans;
    }
};
