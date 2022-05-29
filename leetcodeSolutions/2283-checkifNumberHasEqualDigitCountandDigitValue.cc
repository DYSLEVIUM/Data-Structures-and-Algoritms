class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> mp;
        
        for(auto &ch: num) {
            ++mp[ch - '0'];
        }
        
        for(int i = 0; i < num.size(); ++i) {
            if(mp[i] != num[i] - '0') return false;
        }
        
        return true;
    }
};
