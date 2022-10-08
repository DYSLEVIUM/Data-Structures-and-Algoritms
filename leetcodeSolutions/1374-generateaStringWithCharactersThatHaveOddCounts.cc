class Solution {
public:
    string generateTheString(int n) {
        string ans;
        for(int i = 0; i < n - 1; ++i) {
            ans += 'a';
        }

        if(n & 1) {
            ans += 'a';
        } else {
            ans += 'b';
        }

        return ans;
    }
};
