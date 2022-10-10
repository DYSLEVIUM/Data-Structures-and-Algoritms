class Solution {
public:
    string robotWithString(const string &s) {
        int n = s.size();

        string t;
        vector<char> suff_min(n + 1);
        suff_min[n] = char(127);
        for(int i = n - 1; i >= 0; --i) {
            suff_min[i] = min(suff_min[i + 1], s[i]);
        }

        int idx = 0;
        string ans;
        while(idx < n) {
            if(t.empty() || t.back() > suff_min[idx]) {
                t += s[idx++];
            } else {
                ans += t.back();
                t.pop_back();
            }
        }

        while(!t.empty()) {
            ans += t.back();
            t.pop_back();
        }

        return ans;
    }
};
