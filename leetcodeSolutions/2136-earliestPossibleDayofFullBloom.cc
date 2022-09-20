class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
      // growing time is continuous, but planting time is not, so we can greedily choose the seed with the most growing time, so as to increase the chances of most parallel growing, and hence decreasing the time
      int n = plantTime.size();
      
      vector<pair<int, int>> tot(n);
      for(int i = 0; i < n; ++i) {
        tot[i] = {growTime[i], plantTime[i]};
      }
      sort(tot.rbegin(), tot.rend());
      
      int ans = 0, curr_plant_time = 0;
      for(auto &[gt, pt]: tot) {
        curr_plant_time += pt;
        ans = max(ans, curr_plant_time + gt);
      }
      
      return ans;
    }
};
