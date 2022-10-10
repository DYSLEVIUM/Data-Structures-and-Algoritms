class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "#";
        for(auto &ch : s) {
            if(ch == ans.back()) {
                ans.pop_back();
            } else {
                ans += ch;
            }
        }

        return ans.substr(1);
    }
};
