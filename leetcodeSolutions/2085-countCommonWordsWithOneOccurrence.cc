class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_multiset<string> se1(words1.begin(), words1.end());
        unordered_multiset<string> se2(words2.begin(), words2.end());

        int ans = 0;
        for(auto it = se1.begin(); it != se1.end(); ++it) {
            int cnt1 = se1.count(*it);
            int cnt2 = se2.count(*it);
            ans += cnt1 == 1 && cnt1 == cnt2;
        }

        return ans;
    }
};
