class Solution {
public:
    int longestStrChain(vector<string>& words) {
      sort(words.begin(), words.end(), [](const string &a, const string &b){
        return a.length() < b.length();
      });
      
      int maxx = INT_MIN;
      unordered_map<string, int> dp;
      for(string &word: words) {
        for(int i = 0; i < word.size(); ++i) {
          string pre = word.substr(0, i) + word.substr(i + 1);  //  removing the ith word
          dp[word] = max(dp[word], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1); // if word can be made using pre, we find the maximum
        }
        maxx = max(maxx, dp[word]);
      }
      
      return maxx;
    }
};
