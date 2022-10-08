class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &num : nums) {
            ++mp[num];
        }

        int cnt_p = 0, cnt_l = 0;
        for(auto &[_, freq] : mp) {
            cnt_p += freq / 2;
            cnt_l += freq % 2;
        }

        return {cnt_p, cnt_l};
    }
};
