class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      long long xorr = 0;
      for(int &num: nums) {
        xorr ^= num;
      }
      
      long long lsb = xorr & (-xorr);
      vector<int> buckets(2);
      for(int &num : nums) {
        bool is_set = lsb & num;
        buckets[is_set] ^= num;
      }
      
      return buckets;
    }
};
