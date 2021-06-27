// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        auto editDistance = [](string a, string b) {
            vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1));
        
            for(int i = 0; i < a.length() + 1; ++i) {
              for(int j = 0; j < b.length() + 1; ++j) {
                if (i == 0 || j == 0) {
                  if (i == 0)
                    dp[i][j] = j;
                  else
                    dp[i][j] = i;
                } else {
                  if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                  else
                    dp[i][j] = min({dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1});
                }
              }
            }
        
            return dp[a.length()][b.length()];
        };
    
        return editDistance(s, t);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
