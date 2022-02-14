class Solution {
public:
    int findTheWinner(int n, int k) {
      //  this is basically josephus problem
      // return n > 1 ? (findTheWinner(n-1, k) + k - 1) % n + 1 : 1;
      
      int res = 0;
      for(int i=1;i<=n;++i) res = (res + k) % i;
      return res + 1;
    }
};
