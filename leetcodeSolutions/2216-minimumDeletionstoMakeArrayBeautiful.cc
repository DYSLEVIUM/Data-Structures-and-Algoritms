class Solution {
public:
    int minDeletion(vector<int>& nums) {
      int n = nums.size();
      
      int ans = 0;
      for(int i = 1; i < n; ++i) {
        if((i - ans) & 1) {
          if(nums[i] == nums[i - 1]) ++ans;
        }
      }
      if((n - ans) & 1) ++ans;
      
      return ans;
    }
};
