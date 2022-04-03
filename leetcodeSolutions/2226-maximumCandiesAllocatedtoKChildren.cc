class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
      auto distribute = [&candies, &k](const int& x){
        long long int cnt = 0;
        for(int& candy: candies) cnt += candy / x;
        
        return cnt >= k;
      };
      
      int lo = 1, hi = *max_element(candies.begin(), candies.end());
      while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if(distribute(mid)) lo = mid + 1;
        else hi = mid - 1;
      }
      
      return lo - 1;
    }
};
