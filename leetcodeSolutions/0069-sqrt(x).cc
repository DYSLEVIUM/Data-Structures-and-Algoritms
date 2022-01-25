class Solution {
public:
    int mySqrt(int x) {
      long long int ans = INT_MAX;
      
      double delta = 0.000001;
      
      long double lo = 0, hi = (1<<17);
      while((hi-lo)>delta){
        long double mid = lo + (hi-lo)/2;
        long double expr = mid*mid;
        
        ans = (int)mid;
        
        if(expr==x) return ans;
        else if(expr>x)
          hi = mid-delta;
        else lo = mid+delta;
      }
      
      return (int)ans;
    }
};
