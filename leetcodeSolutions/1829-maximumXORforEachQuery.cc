class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
      int n = nums.size(), xor_val = 0;
      for(int &num: nums) {
        xor_val ^= num;
      }
      
      //  2^maximumBit - 1 will always give the maximum
      xor_val ^= (1 << maximumBit) - 1;
      
      vector<int> ans(n);
      ans[0] = xor_val;
      for(int i = 1; i < n; ++i) {
        ans [i] = xor_val ^= nums[n - i];
      }
      
      return ans;
    }
};
