class Solution {
public:
    int minOperations(vector<int>& nums) {
        cin.tie(nullptr)->sync_with_stdio(false);

        unordered_map<int, int> mp;
        for(const int & num : nums) {
            ++mp[num];
        }

        int ans = 0;
        for(const auto & [k, v]: mp) {
            if(v == 1) {
                return -1;
            }
            ans += v / 3 + !!(v % 3);
        }

        return ans;
    }
};
