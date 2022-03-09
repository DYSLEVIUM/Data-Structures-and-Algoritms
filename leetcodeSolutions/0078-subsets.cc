class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      int n = nums.size();
      int mask = (1 << n);
      
      vector<vector<int>> subsets_arr;      
      for(int i = 0; i < mask; ++i){
        vector<int> curr_set;

        int temp = i;
        int cnt = 0;
        while(temp){
          if(temp & 1) curr_set.push_back(nums[cnt]);
          ++cnt;
          temp >>= 1;
        }
        
        subsets_arr.push_back(curr_set);
      }
      
      return subsets_arr;
    }
};
