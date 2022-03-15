class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
      vector<string> ans;
      
      // as minutes is taking up 6 bits, we bit shit the hours so that we can hold the minutes (we could also have done __builtin_popcount(h) + __builtin_popcount(m))
      for(int h = 0; h < 12; ++h)
        for(int m = 0; m < 60; ++m)
          if(bitset<10>(h << 6 | m).count() == turnedOn) ans.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
        
      return ans;
    }
};
