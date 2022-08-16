class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      
//       int ans = -0x3f3f3f3f;
//       int le_prod = 1, ri_prod = 1;
//       for(int i = 0; i < n; ++i) {
//         le_prod *= nums[i], ri_prod *= nums[n - 1 - i];
//         ans = max({ans, le_prod, ri_prod});
        
//         if(!le_prod) {
//           le_prod = 1;
//         }
        
//         if(!ri_prod) {
//           ri_prod = 1;
//         }
//       }
      
//       return ans;
      
      int mx = nums[0], mn = nums[0];
      int ans = mx;
      for(int i = 1; i < n; ++i) {
        if(nums[i] < 0) {
          swap(mx, mn);
        }
        
        mx = max(nums[i], nums[i] * mx), mn = min(nums[i], nums[i] * mn);
        ans = max(ans, mx);
      }
      
      return ans;
    }
};
