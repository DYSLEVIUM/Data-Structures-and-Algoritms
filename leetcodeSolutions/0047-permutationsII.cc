class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      //  here we can implement our own next_permutation or we can solve it using backtracting or solve it similar to https://leetcode.com/problems/permutations/, i.e., after sorting, do a dfs
      int n = nums.size();
      set<vector<int>> ans_sets;

      sort(nums.begin(), nums.end());
      do{
        ans_sets.insert(nums);
      }while(next_permutation(nums.begin(), nums.end()));
      
      vector<vector<int>> ans;
      for(auto& ans_set: ans_sets){
        ans.push_back(vector<int>(ans_set.begin(), ans_set.end()));
      }
      
      return ans;
    }
};
