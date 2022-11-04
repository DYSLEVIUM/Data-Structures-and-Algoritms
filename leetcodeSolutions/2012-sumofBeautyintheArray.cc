class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref_max(n);
        pref_max[0] = nums[0];
        for(int i = 1; i < n; ++i) pref_max[i] = max(pref_max[i - 1], nums[i]);

        vector<int> suff_min(n);
        suff_min[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; --i) suff_min[i] = min(suff_min[i + 1], nums[i]);
    
        int ans = 0;
        for(int i = 1; i < n - 1; ++i) {
            if(pref_max[i - 1] < nums[i] && suff_min[i + 1] > nums[i]) ans += 2;
            else if(nums[i - 1] < nums[i] && nums[i + 1] > nums[i]) ++ans;          
        }

        return ans;
    }
};
