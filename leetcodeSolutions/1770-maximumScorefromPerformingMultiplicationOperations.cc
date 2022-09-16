class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
      int n = nums.size(), m = multipliers.size();
    
      vector<int> next(m + 1), curr(m + 1);
      for(int op = m - 1; op >= 0; --op) {
        for(int le = 0; le < op + 1; ++le) {
          int ri = (n - 1) - (op - le);
          curr[le] = max(multipliers[op] * nums[le] + next[le + 1], 
                           multipliers[op] * nums[ri] + next[le]);
        }
        next = curr;
      }
      
      return curr[0];
    }
};

class Solution2 {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
      int n = nums.size(), m = multipliers.size();
    
      vector<vector<int>> dp(m + 1, vector<int>(m + 1));
      for(int op = m - 1; op >= 0; --op) {
        for(int le = 0; le < op + 1; ++le) {
          int ri = (n - 1) - (op - le);
          dp[op][le] = max(multipliers[op] * nums[le] + dp[op + 1][le + 1], 
                           multipliers[op] * nums[ri] + dp[op + 1][le]);
        }
      }
      
      return dp[0][0];
    }
};

class Solution1 {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
      int n = nums.size(), m = multipliers.size();
      
      vector<vector<int>> dp(m, vector<int>(m, -1));
      auto recur = [&](const auto &recur, const int &idx, const int &l_ptr){
        if(idx == m) {
          return 0;
        }
        
        if(dp[idx][l_ptr] != -1) {
          return dp[idx][l_ptr];
        }
        
        int r_ptr = n - 1 - (idx - l_ptr);
        
        int le = nums[l_ptr] * multipliers[idx] + recur(recur, idx + 1, l_ptr + 1);
        int ri = nums[r_ptr] * multipliers[idx] + recur(recur, idx + 1, l_ptr);
        
        return dp[idx][l_ptr] = max(le, ri);
      };
      return recur(recur, 0, 0);
    }
};
