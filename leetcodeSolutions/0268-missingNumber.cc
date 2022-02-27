class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int xo = 0;
      for(int i = 1; i < nums.size() + 1; ++i) xo ^= i ^ nums[i-1];
      return xo;
    }
};
