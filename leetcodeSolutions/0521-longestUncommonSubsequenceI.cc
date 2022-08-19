class Solution {
public:
    int findLUSlength(string a, string b) {
      if(a.length() != b.length()) {
        return max(a.length(), b.length());
      }
      
      int n = a.length();
      bool is_same = true;
      for(int i = 0; i < n; ++i) {
        is_same = is_same && a[i] == b[i];
      }
      
      return is_same ? -1 : n;
    }
};
