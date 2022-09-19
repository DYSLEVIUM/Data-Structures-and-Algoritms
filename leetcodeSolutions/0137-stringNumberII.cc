class Solution {
public:
    int singleNumber(vector<int>& nums) {
      constexpr int MAX_BITS = 32;
      
      vector<int> cnt(MAX_BITS);
      for(auto &num : nums){
          for(int bit = 0; bit < MAX_BITS; ++bit){
            cnt[bit] += num & 1;
            num >>= 1;
          }
      }

      int ans = 0;
      for(int i = 0; i < MAX_BITS; ++i){
          if(cnt[i] % 3 != 0) {
            ans += (1 << i);
          }
      }

      return ans;
    }
};
