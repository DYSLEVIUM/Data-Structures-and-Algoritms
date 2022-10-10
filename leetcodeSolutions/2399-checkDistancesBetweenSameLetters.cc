class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if(mp.count(ch)) {
                if(i - mp[ch] - 1 != distance[ch - 'a']) {
                    return false;
                }
            }
            mp[ch] = i;
        }

        return true;
    }
};
