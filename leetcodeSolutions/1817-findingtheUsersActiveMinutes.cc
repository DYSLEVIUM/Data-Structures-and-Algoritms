class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;
        for(auto& log: logs) {
            mp[log[0]].insert(log[1]);
        }
        
        vector<int> ans(k);
        for(auto& [id, sett]: mp) {
            if(sett.size() - 1 < k) ++ans[sett.size() - 1];
        }
        
        return ans;
    }
};
