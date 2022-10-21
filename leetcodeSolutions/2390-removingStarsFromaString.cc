class Solution {
public:
    string removeStars(const string & s) {
        string ans;
        for(auto & ch : s) {
            if(ch == '*' && !ans.empty()) ans.pop_back();
            else ans += ch;
        }
        return ans;
    }
};
