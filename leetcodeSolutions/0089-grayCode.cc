class Solution {
public:
    vector<int> grayCode(int n) {
      /*
        Consider some valid gray code sequence from 0 to 2^(k-1), then we can be certain that 2^k is not part of that code.
For some sequence of k-1 bits if we add 2^k then we have increased the number of bits by 1, i.e. we have prepended a 1 onto the sequence of k-1 bits.
To extend the valid sequence we can add 2^k onto every element of the sequence starting from the end of the sequence to ensure that we don't invalidate the sequence at the start point. This works because we already started with a valid sequence and each new element that we add must differ by exactly 1 bit, doubling the length of the sequence (each element of the original contributes an extra value with 1 prepended to it).
Hence, to generate a valid sequence of n bits, we only need a trivial solution for some k < n.
Starting from n = 0 there is only 1 valid sequence, namely [0].
      */
      vector<int> ans(1, 0);
      
      for(int i = 0; i < n; ++i) {
        int bit = 1 << i;
        int cnt = ans.size();
        
        while(cnt--) ans.push_back(bit + ans[cnt]);
      }
      
      return ans;
    }
};
