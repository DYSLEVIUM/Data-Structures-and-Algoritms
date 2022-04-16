class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
      string new_str = "";
      
      for(auto &ch: s) {
        if(ch != '-') {
          new_str += toupper(ch);
        }
      }
      reverse(new_str.begin(), new_str.end());
      
      string ans = "";
      int cnt = 0;
      for(auto &ch: new_str) {
        if(cnt == k) {
          ans += '-';
          cnt = 0;
        }
        ++cnt;
        ans += ch;
      }
      reverse(ans.begin(), ans.end());
      
      return ans;
    }
};
