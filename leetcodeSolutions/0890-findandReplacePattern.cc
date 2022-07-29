class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        auto normalize_string = [](string a){
            unordered_map<char, char> mp;
            char ch_ptr = 'a';
            
            // assigning unused character to every unique character
            for(auto &ch: a) {
                if(mp.find(ch) == mp.end()) {
                    mp[ch] = ch_ptr++;
                }
            }
            
            // normalizing
            for(auto &ch: a) {
                ch = mp[ch];
            }
            
            return a;
        };

        string normalized_pattern = normalize_string(pattern);
        
        vector<string> ans;
        for(auto &word: words) {
            if(normalized_pattern == normalize_string(word)) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};
