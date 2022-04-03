class Solution {
public:
    int convertTime(string current, string correct) {
      auto convert_to_mins = [](const string& s){
        int total = 0;
        
        int hours = s[0] * 10 + s[1];
        int mins = s[3] * 10 + s[4];
        
        return hours * 60 + mins;
      };
      
      int ans = 0;

      vector<int> mins{60, 15, 5, 1};
      int diff_min = (abs(convert_to_mins(current) - convert_to_mins(correct)));
      for(int i = 0; i < mins.size(); ++i) {
        ans += diff_min / mins[i];
        diff_min %= mins[i];
      }
      
      return ans;
    }
};
