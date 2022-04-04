class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int mask = 1 << n;
        
        set<multiset<int>> ans_set;        
        for(int i = 0; i < mask; ++i) {
            int temp = i;
            multiset<int> curr_ans_set;
            int iter = 0;
            while(temp) {
                if(temp & 1) curr_ans_set.insert(nums[iter]);
                ++iter;
                temp >>= 1;
            }
            
            ans_set.insert(curr_ans_set);
        }
        
        vector<vector<int>> ans;
        for(auto& it: ans_set) {
            ans.push_back(vector<int>(it.begin(), it.end()));
        }
        
        return ans;
    }
};
