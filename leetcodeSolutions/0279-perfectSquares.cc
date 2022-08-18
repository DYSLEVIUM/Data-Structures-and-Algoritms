class Solution {
public:
    int numSquares(int n) {
      vector<int> sqs;
      int i = 1;
      while(i * i <= n) {
        sqs.push_back(i * i);
        ++i;
      }
      
      int sz = sqs.size();
      vector<int> prev(n + 1, 0x3f3f3f3f), curr(n + 1, 0x3f3f3f3f);
      for(int i = 0; i < sz + 1; ++i) {
        for(int j = 0; j < n + 1; ++j) {
          if(!i || !j) {
            if(!j) {
              curr[j] = 0;
            }
            continue;
          }
          
          if(j - sqs[i - 1] >= 0) 
            curr[j] = min(prev[j], 1 + curr[j - sqs[i - 1]]);
          else 
            curr[j] = prev[j];
        }
        
        prev = curr;
      }
      
      return curr[n];
    }
};
