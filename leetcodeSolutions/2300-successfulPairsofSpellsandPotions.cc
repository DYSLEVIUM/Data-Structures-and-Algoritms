class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      int n = spells.size();

      sort(potions.begin(), potions.end());
      
      vector<int> ans(n);
      for(int i = 0; int &spell: spells) {
        long long search_val = ceil(1.0 * success / spell);
        int idx = lower_bound(potions.begin(), potions.end(), search_val) - potions.begin();
        
        ans[i++] = potions.size() - idx;
      }
      
      return ans;
    }
};
