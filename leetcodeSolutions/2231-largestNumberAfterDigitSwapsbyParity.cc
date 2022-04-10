class Solution {
public:
    int largestInteger(int num) {
      vector<int> odd, even;
      
      string s = to_string(num);
      int n = s.length();
      for(int i = 0; i < n; ++i) {
        if((s[i] - '0') & 1) {
          odd.push_back(s[i] - '0');
          s[i] = '1';
        } else {
          even.push_back(s[i] - '0');
          s[i] = '0';
        }
      }
      sort(odd.begin(), odd.end());
      sort(even.begin(), even.end());
      
      int nnum = 0;
      for(int i = 0; i < n; ++i) {
        if(s[i] - '0') {
          nnum = nnum * 10 + odd.back();
          odd.pop_back();
        } else {
          nnum = nnum * 10 + even.back();
          even.pop_back();
        }
      }
      
      return nnum;
    }
};
