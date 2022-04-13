class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.length();
      
//       //  dp -> here we check s[i] == s[j] and the if the inside is a palindrome or not
//       vector<vector<bool>> dp(n, vector<bool>(n));

//       int l_ptr = 0, r_ptr = 0;

//       //  initialization
//       //  string of length 1 is a palindrome
//       for(int i = 0; i < n; ++i) dp[i][i] = 1;
      
//       //  string of lenght 2 is a palindrome
//       for(int i = 0; i < n - 1; ++i) {
//         if(s[i] == s[i + 1]) {
//           dp[i][i + 1] = 1;
//           l_ptr = i, r_ptr = i + 1;
//         }
//       }
      
//       //  string of length > 2
//       for(int len = 3; len <= n; ++len) {
//         for(int i = 0; i < n - len + 1; ++i) {
//           int j = i + len - 1;
//           if(s[i] == s[j] && dp[i + 1][j - 1]) {
//             dp[i][j] = 1;
            
//             if(j - i + 1 > r_ptr - l_ptr + 1) {
//               r_ptr = j, l_ptr = i;
//             }
//           }
//           else dp[i][j] = 0;
//         }
//       }
      
//       return s.substr(l_ptr, r_ptr - l_ptr + 1);

      //  greedy
      auto expand = [&s, &n](int& l, int& r){
        while(l >= 0 && r < n && s[l] == s[r]) {
          --l, ++r;
        }
        
        ++l, --r;
      };
      
      int l_ptr, r_ptr;
      int len = INT_MIN;
      
      //  we expand outwards from s[i]
      for(int i = 0; i < n; ++i) {
        int curr_l_ptr, curr_r_ptr;
        int curr_len;
        
        //  for odd length
        curr_l_ptr = i, curr_r_ptr = i;
        expand(curr_l_ptr, curr_r_ptr);
        
        curr_len = curr_r_ptr - curr_l_ptr + 1;
        if(curr_len > len) {
          l_ptr = curr_l_ptr, r_ptr = curr_r_ptr;
          len = curr_len;
        }
        
        // for even length
        curr_l_ptr = i, curr_r_ptr = i + 1;
        expand(curr_l_ptr, curr_r_ptr);

        curr_len = curr_r_ptr - curr_l_ptr + 1;
        if(curr_len > len) {
          l_ptr = curr_l_ptr, r_ptr = curr_r_ptr;
          len = curr_len;
        }
      }
      
      return s.substr(l_ptr, r_ptr - l_ptr + 1);
    }
};
