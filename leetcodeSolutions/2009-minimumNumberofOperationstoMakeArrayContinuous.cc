class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        set<int> se(nums.begin(), nums.end());
        vector<int> unique(se.begin(), se.end());

        int ans = 0x3f3f3f;
        // binary search ans
        // for(int i = 0; i < unique.size(); ++i) {
        //     int left = unique[i];
        //     int right = left + n - 1;

        //     int right_pos = upper_bound(unique.begin(), unique.end(), right) - unique.begin();

        //     int count = right_pos - i; // we have this much elements in the middle, so we need to change the other numbers
        //     ans = min(ans, n - count);
        // }

        // sliding window answer, this is faster as it runs for O(n), but the overall time complexity is still O(nlogn)
        int right_pos = 0;
        for(int i = 0; i < unique.size(); ++i) {
            while(right_pos < unique.size() && unique[i] + n > unique[right_pos]) {
                ++right_pos;
            }

            int count = right_pos - i;
            ans = min(ans, n - count);
        }

        return ans;
    }
};
