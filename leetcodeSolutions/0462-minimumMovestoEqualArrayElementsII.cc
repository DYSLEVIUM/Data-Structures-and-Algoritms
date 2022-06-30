class Solution {
public:
    int minMoves2(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      
      if(n == 1) {
        return 0;  
      }
      
      if(n == 2) {
        return nums.back() - nums.front();  
      }
      
      auto get_moves = [&](const int &idx){
        long long moves = 0;
        for(int i = 0; i < n; ++i) {
          moves += abs(nums[i] - nums[idx]);
        }
        
        return moves;
      };
      
      return min(1LL * get_moves(n / 2), 1LL * get_moves(n / 2 + 1));
    }
};
