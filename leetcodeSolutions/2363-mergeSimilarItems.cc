class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for(auto &item : items1) {
            mp[item[0]] += item[1];
        }
        
        for(auto &item : items2) {
            mp[item[0]] += item[1];
        }
        
        vector<vector<int>> ans;
        for(auto &[item, cnt] : mp) {
            ans.push_back({ item, cnt });
        }
        
        return ans;
    }
};
