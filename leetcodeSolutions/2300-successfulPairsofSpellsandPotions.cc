class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      sort(potions.begin(), potions.end());
      
      int np = potions.size();
      int ns = spells.size();
      vector<int> ans(ns);
      for(int i = 0; i < ns; ++i) {
        long long x = ceil(1.0 * success / spells[i]);
        int idx = lower_bound(potions.begin(), potions.end(), x) - potions.begin();
        ans[i] = max(0, np - idx);
      }
      
      return ans;
    }
};
