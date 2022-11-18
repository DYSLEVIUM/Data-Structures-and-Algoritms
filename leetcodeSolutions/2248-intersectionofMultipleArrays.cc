class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        auto get_inter = [](vector<int> &a, vector<int> &b){
            if(a.size() > b.size()) swap(a, b);
            unordered_set<int> se(a.begin(), a.end());
            vector<int> curr;
            for(auto & num : b) if(se.count(num)) curr.push_back(num);
            return curr;
        };

        vector<int> ans = nums[0];
        for(int i = 1; i < nums.size(); ++i) ans = get_inter(ans, nums[i]);
      
        sort(ans.begin(), ans.end());
        return ans;
    }
};
