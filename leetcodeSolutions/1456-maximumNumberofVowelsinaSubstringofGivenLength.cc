class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> se{'a', 'e', 'i', 'o', 'u'};
        int cnt = 0, maxx = 0;
        for(int i = 0; i < k - 1; ++i) {
            cnt += se.count(s[i]);
        }

        for(int i = k - 1; i < s.size(); ++i) {
            cnt += se.count(s[i]);
            maxx = max(maxx, cnt);

            cnt -= se.count(s[i - k + 1]);
        }

        return maxx;
    }
};
