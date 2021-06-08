class Solution {
 public:
  string longestNiceSubstring(string s) {
    if (s.size() < 2) return "";

    unordered_set<char> us(s.begin(), s.end());

    for (long long i = 0; i < s.size(); ++i) {
      if (us.find(toupper(s[i])) == us.end() || us.find(tolower(s[i])) == us.end()) {
        string s1 = longestNiceSubstring(s.substr(0, i));
        string s2 = longestNiceSubstring(s.substr(i + 1));

        return s1.size() >= s2.size() ? s1 : s2;
      }
    }

    return s;
  }
};
