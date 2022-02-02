class Solution {
public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;

      int n = s.length();

      auto is_palindrome = [&s](int st, int ed){
        while(st < ed){
          if(s[st++] != s[ed--]) return false;
        }
        return true;
      };

      auto find_all = [&s, &ans, &n, &is_palindrome](const auto& find_all, const int& point, vector<string> curr_par)->void{
        if(point == n) ans.push_back(curr_par);
        else{
          for(int i=point;i<n;++i){
            if(is_palindrome(point, i)){
              curr_par.push_back(s.substr(point, i - point + 1));
              find_all(find_all, i + 1, curr_par);
              curr_par.pop_back();
            }
          }
        }
      };
      
      find_all(find_all, 0, {});
      return ans;
    }
};
