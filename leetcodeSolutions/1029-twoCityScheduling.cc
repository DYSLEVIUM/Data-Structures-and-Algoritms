class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
      int n = costs.size() / 2;

      //  using quick sort
      nth_element(costs.begin(), costs.begin() + n, costs.end(), [](const vector<int>& x, const vector<int>& y){
        return x[0] - x[1] < y[0] - y[1];
      });

//       sort(costs.begin(), costs.end(), [](const vector<int>& x, const vector<int>& y){
//         return x[0] - x[1] < y[0] - y[1];
//       });
      
      int ans = 0;
      for(int i = 0; i < n; ++i) {
        ans += costs[i][0] + costs[n + i][1];
      }
      
      return ans;
    }
};
