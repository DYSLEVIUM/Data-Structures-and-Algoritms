class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
      int n = releaseTimes.size();
      
      char ans = keysPressed[0];
      int max_duration = releaseTimes[0];
      for(int i = 1; i < n; ++i) {
        int curr_duration = releaseTimes[i] - releaseTimes[i - 1];
        
        if(curr_duration >= max_duration) {
          if(curr_duration == max_duration) ans = max(ans, keysPressed[i]);
          else {
            ans = keysPressed[i];
            max_duration = curr_duration;
          }
        }
      }
      
      return ans;
    }
};
