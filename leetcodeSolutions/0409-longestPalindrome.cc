class Solution {
public:
    int longestPalindrome(string s) {
      unordered_map<char, int> mp;
      for(char& ch: s) ++mp[ch];

      bool exists_odd = false;
      int ans = 0;
      for(auto& [ch, cnt]: mp){
        ans += 2 * (cnt / 2);
        if(cnt & 1) exists_odd = true;
      }
      
      if(ans %2 == 0 && exists_odd) ++ans;
      return ans;
    }
};
