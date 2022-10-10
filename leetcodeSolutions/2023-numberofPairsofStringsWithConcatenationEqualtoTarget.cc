class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_multiset<string> se(nums.begin(), nums.end());

        int cnt = 0, t_n = target.size();
        for(int i = 0; i < t_n - 1; ++i) {
            string pref = target.substr(0, i + 1);
            string suff = target.substr(i + 1, t_n - (i + 1));

            cnt += se.count(pref) * (se.count(suff) - (pref == suff));
        }

        return cnt;
    }
};
