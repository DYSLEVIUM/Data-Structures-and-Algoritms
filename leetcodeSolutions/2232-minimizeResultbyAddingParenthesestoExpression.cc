class Solution {
public:
    string minimizeResult(string expression) {
      int n = expression.length();
      auto get_inside = [](const string &s){
        int i = 0;
        while(s[i] != '(') ++i;
        
        int j = i;
        while(s[j] != ')') ++j;

        int k = i;
        while(s[k] != '+') ++k;
        
        if(i + 1 == k || j - 1 == k) return 1LL * INT_MAX;
        
        long long num1 = 0;
        for(int l = i + 1; l < k; ++l) num1 = num1 * 10 + (s[l] - '0');
        
        long long num2 = 0;
        for(int l = k + 1; l < j; ++l) num2 = num2 * 10 + (s[l] - '0');
        
        return num1 + num2;
      };
      
      int k = 0;
      while(expression[k] != '+') ++k;

      long long minn = INT_MAX;
      string ans = "";
      for(int i = 0; i < k; ++i) {
        for(int j = k + 1; j < n; ++j) {
          string s = "";
          s += expression.substr(0, i);
          long long num1 = s.empty() ? 1 : stoll(s);
          s += "(";
          s += expression.substr(i, k - i);
          
          string t = "";
          t += expression.substr(k + 1, j - k);
          
          string tt = expression.substr(j + 1, n - j - 1);
          long long num2 = tt.empty() ? 1 : stoll(tt);
          
          t += ")";
          t += expression.substr(j + 1, n - j - 1);
          
          string temp = s;
          temp += "+";
          temp += t;
          
          int curr_total = num1 * num2 * get_inside(temp);
          
          if(curr_total < minn) {
            minn = curr_total;
            ans = temp;
          }
        }
      }
      
      return ans;
    }
};
