class Solution {
public:
    string decodeMessage(string key, string message) {
        constexpr int CHAR_SET = 26;
        static_assert(CHAR_SET == 26);

        unordered_map<char, char> mp;
        mp[' '] = ' ';
        int iter = 0;

        for(auto &ch : key) {
            if(mp.count(ch)) {
                continue;
            }
            mp[ch] = iter + 'a';
            ++iter;
        }

        string ans;
        for(auto & ch : message) {
            ans += mp[ch];
        }

        return ans;
    }
};
