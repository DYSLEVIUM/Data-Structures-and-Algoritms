class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int i = 0;
        for(int j = n - n / 2; j < n; ++j) { // after the first n / 2 numbers, we match the smallest numbers with the smallest numbers in the second half
            i += 2 * nums[i] <= nums[j];
        }

        return i << 1;
    }
};
