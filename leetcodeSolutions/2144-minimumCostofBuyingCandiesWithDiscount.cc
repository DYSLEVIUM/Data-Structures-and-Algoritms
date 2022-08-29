class Solution {
public:
    int minimumCost(vector<int>& cost) {
      int n = cost.size();
      
      sort(cost.rbegin(), cost.rend());
      
      int ans = 0;
      for(int i = 0; i < n; i += 3) {
        ans += cost[i] + (i + 1 < n ? cost[i + 1] : 0);
      }
      
      return ans;
    }
};
