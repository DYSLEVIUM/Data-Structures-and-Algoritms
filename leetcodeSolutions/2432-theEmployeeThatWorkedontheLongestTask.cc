class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int id = INT_MAX, maxx = INT_MIN, prev = 0;
        for(auto &log : logs) {
            int time = log[1] - prev;
            if(time > maxx || (time == maxx && log[0] < id)) {
                id = log[0];
                maxx = time;
            }
            prev = log[1];
        }
      
      return id;
    }
};
