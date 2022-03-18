class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
      int n = timeSeries.size();
      
      int ans = 0, last_poisoned = timeSeries[0];
      for(int i = 1; i < n; ++i) {
        if(timeSeries[i] > last_poisoned + duration - 1) ans += duration;
        else if(timeSeries[i] == last_poisoned + duration - 1) ans += duration - 1;
        else ans += timeSeries[i] - last_poisoned;
        last_poisoned = timeSeries[i];
      }
      
      ans += duration;
      
      return ans;
    }
};
