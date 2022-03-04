class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> mp;
      
      for(auto& str: strs){
        string te = str;
        sort(te.begin(), te.end());
        
        mp[te].push_back(str);
      }
      
      vector<vector<string>> ans;
      for(auto& ana: mp) ans.push_back(ana.second);
      
      return ans;
    }
};
