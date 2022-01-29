class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      constexpr int BITS = 32;
      bitset<BITS> num_bits;
      
      int bit = 0;
      while(n){
        num_bits[BITS-1-bit++] = n&1;
        n>>=1;
      }
      
      return num_bits.to_ullong();
    }
};
