class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
      long long lo = 1, hi = 1e14;
      
      auto check = [&bus_times = time, &totalTrips](const long long& x){
        long long cnt = 0;
        for(int& bus_time: bus_times){
          cnt += x / bus_time;
        }
        return cnt >= totalTrips;
      };
      
      long long ans = 0;
      while(lo <= hi){
        long long mid = lo + (hi - lo) / 2;
        
        if(check(mid)) ans = mid, hi = mid - 1;
        else lo = mid + 1;
      }
      
      return ans;
    }
};
