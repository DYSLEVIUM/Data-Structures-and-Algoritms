class Solution {
public:
    string makeGood(string s) {
        string ans;
        for(char & ch : s) {
            if(!ans.empty() && abs(ans.back() - ch) == abs('A' - 'a')) ans.pop_back();
            else ans += ch;
        }

        return ans;
    }
};
