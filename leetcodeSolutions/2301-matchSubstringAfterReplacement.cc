class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
      const int CHAR_SET = 256;
      vector<vector<bool>> all_mappings(CHAR_SET, vector<bool>(CHAR_SET, false));
      for(int i = 0; i < CHAR_SET; ++i) {
        //  this implies no change was necessary
        all_mappings[i][i] = true;
      }
      
      for(vector<char> &mapping: mappings) {
        all_mappings[mapping[0]][mapping[1]] = true;
      }
      
      for(int i = 0; i < s.size() - sub.size() + 1; ++i) {
        bool found = true;
        for(int j = 0; j < sub.size(); ++j) {
          //  can sub[j] be converted to s[i + j]
          if(!all_mappings[sub[j]][s[i + j]]) {
            found = false;
            break;
          }
        }
        
        if(found) {
          return true;
        }
      }
      
      return false;
    }
};
