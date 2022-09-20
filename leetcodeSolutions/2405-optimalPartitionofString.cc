class Solution {
public:
    int partitionString(string s) {
      unordered_set<char> se;
      int part = s.empty() ? 0 : 1;
      for(auto &ch : s) {
        if(se.count(ch)) {
          se.clear();
          ++part;
        }
        se.insert(ch);
      }
      
      return part;
    }
};
