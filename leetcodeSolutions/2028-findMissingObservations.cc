class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
      int m = rolls.size();
      int rem = mean * (m + n) - accumulate(rolls.begin(), rolls.end(), 0);
      
      if(rem < n || rem > 6 * n) {
        return {};
      }
      
      int val = rem / n;
      vector<int> ans(n, val);
      for(int i = 0; i < rem - val * n; ++i) {
        ++ans[i];
      }
      
      return ans;
    }
};
