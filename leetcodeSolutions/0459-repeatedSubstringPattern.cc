class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      //  we want to check if the string is periodic or not
      //  (i + z[i] = n && n % i == 0) (periodic with period i)
      
      int n = (int) s.length();
      auto z_function = [&n](const string &s) {
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
      };
      auto z = z_function(s);
      
      for(int i = 0; i < n; ++i) {
        if(i + z[i] == n && n % i == 0) return true;
      }
      
      return false;
    }
};
