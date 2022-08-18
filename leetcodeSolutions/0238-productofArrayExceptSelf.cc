class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      
      if(n == 1) {
        return nums;
      }
      
      vector<int> pref(nums.begin(), nums.end());
      for(int i = 1; i < n; ++i) {
        pref[i] *= pref[i - 1];
      }
      
      vector<int> suff(nums.begin(), nums.end());
      for(int i = n - 2; i >= 0; --i) {
        suff[i] *= suff[i + 1];
      }
      
      vector<int> ans(n);
      ans[0] = suff[1];
      ans[n - 1] = pref[n - 2];
      
      for(int i = 1; i < n - 1; ++i) {
        ans[i] = pref[i - 1] * suff[i + 1];
      }
      
      return ans;
    }
};
