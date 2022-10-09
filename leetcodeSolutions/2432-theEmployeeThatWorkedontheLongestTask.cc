class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
      int id = INT_MAX, maxx = INT_MIN, prev = 0;
      for(auto &log : logs) {
        int time = log[1] - prev;
        if(time >= maxx) {
          if(time == maxx) {
            id = min(id, log[0]);
          } else {
            id = log[0];
          }
          maxx = max(maxx, time);
        }
        prev = log[1];
      }
      
      return id;
    }
};
