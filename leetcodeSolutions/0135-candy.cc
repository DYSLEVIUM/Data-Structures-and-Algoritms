class Solution {
public:
    int candy(vector<int>& ratings) {
      int n = ratings.size();
      vector<int> left_to_right(n, 1), right_to_left(n, 1);
      
      for(int i = 1; i < n; ++i) {
        if(ratings[i] > ratings[i - 1]) {
          left_to_right[i] = left_to_right[i - 1] + 1;
        }
      }
      
      for(int i = n - 2; i >= 0; --i) {
        if(ratings[i] > ratings[i + 1]) {
          right_to_left[i] = right_to_left[i + 1] + 1;
        }
      }
      
      int sum = 0;
      for(int i = 0; i < n; ++i) {
        sum += max(left_to_right[i], right_to_left[i]);
      }
      
      return sum;
    }
};
