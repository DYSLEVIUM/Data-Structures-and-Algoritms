class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      int n = candidates.size();    
      set<multiset<int>> ans_sets;
      auto get_ans = [&n, &candidates, &ans_sets](const auto& get_ans, const int& curr_target, multiset<int>& curr_ans_set) -> void {
        if(curr_target == 0){
          ans_sets.insert(curr_ans_set);
          return;
        }
        
        if(curr_target < 0) return; //  not possible
        
        for(int i = 0; i < n; ++i){
          curr_ans_set.insert(candidates[i]);
          get_ans(get_ans, curr_target - candidates[i], curr_ans_set);
          
          //  backtracking
          curr_ans_set.erase(curr_ans_set.find(candidates[i]));
        }
      };
      multiset<int> curr_ans_set;
      get_ans(get_ans, target, curr_ans_set);
      
      vector<vector<int>> ans;
      for(auto& ans_set: ans_sets) ans.push_back(vector<int>(ans_set.begin(), ans_set.end()));
      
      return ans;
    }
};
