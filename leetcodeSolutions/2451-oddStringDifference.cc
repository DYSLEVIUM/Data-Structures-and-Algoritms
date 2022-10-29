class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words[0].size();
        auto calculate_diff = [&](const string & s){
            string diff;
            for(int i = 1; i < n; ++i) diff += s[i] - s[i - 1]; 
            return diff;
        };
        
        unordered_map<string, pair<int, string>> mp;
        for(auto & word : words) {
            string diff = calculate_diff(word);
            mp[diff] = {mp[diff].first + 1, word};
        }
        
        for(auto & [_, pp] : mp) {
            if(pp.first == 1) return pp.second;
        }
        
        return "";
    }
};
