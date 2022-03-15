class Solution {
public:
    bool isPerfectSquare(int num) {
      int lo = 1, hi = (1 << 16);
      while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        long long sq = 1LL * mid * mid;
          
        if(sq == num) return true;
        else if (sq > num) hi = mid - 1;
        else lo = mid + 1;
      }
      
      return false;
    }
};
