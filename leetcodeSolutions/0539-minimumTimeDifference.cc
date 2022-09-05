class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
      int n = timePoints.size(), total = 24 * 60;;
      vector<int> res(n);
      transform(timePoints.begin(), timePoints.end(), res.begin(), [&](const string &s){
        int hrs = s[0] * 10 + s[1];
        int mins = s[3] * 10 + s[4];
        
        return (hrs * 60 + mins) % total;
      });
      sort(res.begin(), res.end());
      
      int minn = INT_MAX;
      for(int i = 1; i < n; ++i) {
        minn = min(minn, res[i] - res[i - 1]); // looking backwards
        minn = min(minn, (res[i - 1] - res[i] + total) % total); // looking forwards
      }
      
      // edge case: last with first
      minn = min(minn, (res[0] - res[n - 1] + total) % total);
      minn = min(minn, res[n - 1] - res[0]);
      
      return minn;
    }
};
