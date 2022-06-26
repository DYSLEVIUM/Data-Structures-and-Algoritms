class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      //  find the subarray with minimum sum of size = n - k
      int n = cardPoints.size();
      int win_size = n - k;
      auto total_sum = accumulate(cardPoints.begin(), cardPoints.end(), 0LL);
      
      if(k >= n) {
        return total_sum;
      }
      
      int sum = 0;
      for(int i = 0; i < win_size - 1; ++i) {
        sum += cardPoints[i];
      }
      
      int minn = INT_MAX;
      for(int i = win_size - 1; i < n; ++i) {
        sum += cardPoints[i];
        minn = min(minn, sum);
        sum -= cardPoints[i - win_size + 1];
      }
      
      return total_sum - minn;
    }
};
