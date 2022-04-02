class Solution {
public:
    long long numberOfWays(string s) {
      int n = s.length();
      
      vector<vector<long long>> pref(n, vector<long long>(2));
      pref[0][0] = s[0] == '0';
      pref[0][1] = s[0] == '1';
      for(int i = 1; i < n; ++i) {
        pref[i][0] += pref[i - 1][0] + (s[i] == '0');
        pref[i][1] += pref[i - 1][1] + (s[i] == '1');
        
      }
      
      vector<vector<long long>> suff(n, vector<long long>(2));
      suff[n - 1][0] = s[n - 1] == '0';
      suff[n - 1][1] = s[n - 1] == '1';
      for(int i = n - 2; i >= 0 ; --i) {
        suff[i][0] += suff[i + 1][0] + (s[i] == '0');
        suff[i][1] += suff[i + 1][1] + (s[i] == '1');
      }
      
      long long ans = 0;
      for(int i = 1; i < n - 1; ++i) {
        if(s[i] == '0') {
          long long left_1 = pref[i - 1][1];
          long long right_1 = suff[i + 1][1];
          
          ans += left_1 * right_1;
        }else {
          long long left_0 = pref[i - 1][0];
          long long right_0 = suff[i + 1][0];
          
          ans += left_0 * right_0;
        }
      }
      
      return ans;
    }
};
