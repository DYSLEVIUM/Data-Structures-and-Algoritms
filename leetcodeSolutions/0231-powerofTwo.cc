class Solution {
public:
    bool isPowerOfTwo(int n) {
      return n != 0 && ceil(log2(n)) == floor(log2(n));   
    }
};
