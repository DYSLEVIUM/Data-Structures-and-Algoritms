class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string ans;
        for(int i = 0; i < n; ++i) {
            if(!ans.empty() && abs(ans.back() - s[i]) == abs('A' - 'a')) ans.pop_back();
            else ans += s[i];
        }

        return ans;
    }
};
