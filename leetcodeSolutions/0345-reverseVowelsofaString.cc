class Solution {
public:
    string reverseVowels(string s) {
      unordered_set<char> se({'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'});

      int n = s.length();
      deque<int> dq;
      for(int i = 0; i < n; ++i) if(se.find(s[i]) != se.end()) dq.push_back(i);
      
      while(dq.size() > 1){
        int fr = dq.front();
        int bk = dq.back();
        dq.pop_front(), dq.pop_back();
        
        swap(s[fr], s[bk]);
      }
      
      return s;
    }
};
