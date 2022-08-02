// using lcs method
// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//       string t = s;
//       reverse(t.begin(), t.end());
      
//       auto lcs = [](const string& x, const string& y){
//         int n1 = x.length(), n2 = y.length();
//         vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        
//         for(int i = 1; i < n1 + 1; ++i) {
//           for(int j = 1; j < n2 + 1; ++j) {
//             if(x[i - 1] == y[j - 1]) {
//               dp[i][j] = 1 + dp[i - 1][j - 1];
//             } else {
//               dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//           }
//         }
      
//         return dp[n1][n2];
//       };
      
//       return lcs(s, t);
//     }
// };

// using gap method
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(n));
        for(int gap = 0; gap < n; ++gap) {
            for(int i = 0, j = gap; j < n; ++i, ++j) {
                if(!gap) {
                    // initialization
                    dp[i][j] = 1;
                    continue;
                }
                // this if is not needed as we only need dp value at i >= j, which is covered in the next if condition, i.e., if j > i, we get 2 + 0, which is what we wanted
                // if(gap == 2) {
                //     dp[i][j] = s[i] == s[j] ? 2 : 1;
                //     continue;
                // }
                if(s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
