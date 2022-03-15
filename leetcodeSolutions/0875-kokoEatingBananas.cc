class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int n = piles.size();
      
      auto bananas_per_hour = [&piles, &n](const int& x){
        int total_hours = 0;
        for(int& pile: piles) total_hours += ceil(1.0 * pile / x);
        
        return total_hours;
      };
      
      int lo = 1, hi = INT_MAX;
      while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if(bananas_per_hour(mid) <= h) hi = mid - 1;
        else lo = mid + 1;
      }
      
      return lo;
    }
};
