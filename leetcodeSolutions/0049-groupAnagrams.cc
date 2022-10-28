class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;
        for(int i = 0; i < strs.size(); ++i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto & [_, vec] : mp) {
            vector<string> curr_ans;
            for(int i : vec) curr_ans.push_back(strs[i]);
            ans.push_back(curr_ans);
        }

        return ans;
    }
};
