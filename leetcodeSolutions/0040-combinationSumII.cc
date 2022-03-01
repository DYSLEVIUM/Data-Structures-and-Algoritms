class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      int n = candidates.size();
      vector<vector<int>> ans;
      auto get_ans = [&candidates, &n, &ans](const auto& get_ans, const int& curr_target, vector<int>& curr_ans, const int& curr_idx){
        if(curr_target == 0){
          ans.push_back(curr_ans);
          return;
        }

        for(int i = curr_idx; i < n; i++){
            if(candidates[i] > curr_target) break; 
            if(i > curr_idx && candidates[i] == candidates[i-1]) continue;  //  take element at curr_idx, if the front numbers are same don't take to avoid duplicate
                
            curr_ans.push_back(candidates[i]);
            get_ans(get_ans, curr_target - candidates[i], curr_ans, i + 1);
            curr_ans.pop_back();
        }
      };
      
      sort(candidates.begin(), candidates.end());
      vector<int> curr_ans;
      get_ans(get_ans, target, curr_ans, 0);
      
      return ans;
    }
};
