class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
      int n = s.size();
      vector<string> ans;
      auto insert_dots = [&](const auto &insert_dots, const int &count, const int &idx, const string &curr_ans){
        if(count == 4 && idx > n - 1) {
          string str = curr_ans;
          str.pop_back();
          ans.push_back(str);
          return;
        }

        for(int i = 1; (idx + i < n + 1) && i < 4; ++i) {
          string num = s.substr(idx, i);
          if (num[0] == '0' && i != 1) {
            break;
          } else if(stoi(num) < 256) {
            insert_dots(insert_dots, count + 1, idx + i, curr_ans + num + ".");
          }
        }
      };
      insert_dots(insert_dots, 0, 0, "");
      
      return ans;
    }
};
