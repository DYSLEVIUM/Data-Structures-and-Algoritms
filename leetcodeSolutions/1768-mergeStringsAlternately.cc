class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;

        int p1 = 0, p2 = 0;
        while(p1 < word1.size() && p2 < word2.size()) {
            ans += word1[p1++];
            ans += word2[p2++];
        }

        while(p1 < word1.size()) {
            ans += word1[p1++];
        }

        while(p2 < word2.size()) {
            ans += word2[p2++];
        }

        return ans;
    }
};
