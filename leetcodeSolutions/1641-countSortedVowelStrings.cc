class Solution {
public:
    int countVowelStrings(int n) {
      //  u, o, z, i, e, a
      vector<int> dp(5, 1);
      
      while(n--) {
        //  how many characters can we add to the previous vowel total till i - 1
        for(int i = 1; i < 5; ++i) dp[i] += dp[i - 1];
      }
      
      return dp[4];
    }
};
