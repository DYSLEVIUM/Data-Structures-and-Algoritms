class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
      int n = queries.size();
      vector<long long> ans(n);
      if(intLength & 1) {
        for(int i = 0; i < n; ++i) {
          int query = queries[i];
          
          string le = to_string((long long)(pow(10, intLength / 2)) + (1LL * query - 1LL));
          string ri = le;
          ri.pop_back();
          reverse(ri.begin(), ri.end());
          
          string ans_str = le + ri;
          if(ans_str.length() != intLength) ans[i] = -1;
          else ans[i] = stoll(ans_str);
        }
      } else {
        for(int i = 0; i < n; ++i) {
          int query = queries[i];
          
          string le = to_string((long long)(pow(10, (intLength - 1) / 2)) + (1LL * query - 1LL));
          string ri = le;
          reverse(ri.begin(), ri.end());

          string ans_str = le + ri;
          if(ans_str.length() != intLength) ans[i] = -1;
          else ans[i] = stoll(ans_str);
        }
      }
      
      return ans;
    }
};
