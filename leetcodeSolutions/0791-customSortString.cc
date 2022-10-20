class Solution {
public:
    string customSortString(string order, string s) {
        static constexpr int CHAR_SET = 26;
        int n_o = order.size(), n_s = s.size();

        int fa[CHAR_SET] = {};
        for(auto &ch : s) ++fa[ch - 'a'];

        string ans;
        for(auto &ch : order) {
            while(fa[ch - 'a']) ans += ch, --fa[ch - 'a'];
        }

        for(auto &ch : s) {
            while(fa[ch - 'a']) ans += ch, --fa[ch - 'a'];
        }
        
        return ans;
    }
};
