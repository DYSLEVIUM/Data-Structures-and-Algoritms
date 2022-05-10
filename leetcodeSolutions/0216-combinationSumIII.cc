class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
      vector<vector<int>> ans;
      
      int total_subsets = (1 << (nums.size()));
      for(int i = 0; i < total_subsets; ++i) {
        int temp = i;
        int iter = 0;
        int sum = 0;
        int cnt = 0;
        
        vector<int> curr_ans;
        while(temp){
          if(temp & 1){
            curr_ans.push_back(nums[iter]);    
            
            sum += nums[iter];
            ++cnt;
          }
          
          temp >>= 1;
          ++iter;
        }

        if(cnt == k && sum == n) {
          ans.push_back(curr_ans);
        }
      }
      
      return ans;
    }
};
