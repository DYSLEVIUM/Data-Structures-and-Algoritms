class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        cin.tie(nullptr)->sync_with_stdio(false);

        constinit static int MOD = 1e9 + 7;

        auto rev = [](const int & num){
            string s = to_string(num);
            reverse(s.begin(), s.end());
            return stoi(s);
        };

        int ans = 0;
        unordered_map<int, int> mp;
        for(const int & num : nums) {
            int key = num - rev(num);

            ans += mp[key];
            ans %= MOD;

            ++mp[key];
        }

        return ans;
    }
};
