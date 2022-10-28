class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n + 1);
        for(int i = 1; i < n + 1; ++i) pref[i] = nums[i - 1] ? 1 + pref[i - 1] : 0;
    
        vector<int> suff(n + 1);
        for(int i = n - 1; i >= 0; --i) suff[i] = nums[i] ? 1 + suff[i + 1] : 0;

        int maxx = 0;
        for(int i = 1; i < n + 1; ++i) maxx = max(maxx, pref[i - 1] + suff[i]);
        return maxx;
    }
};
