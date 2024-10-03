class Solution {
public:
    int minSubarray(vector<int>& nums, const int & p) {
        static const int INF = 0x3f3f3f3f;

        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            sum %= p;
        }

        int target = sum % p;
        if(!target) {
            return 0;
        }

        unordered_map<int, int> mp;
        mp[0] = -1;

        int minn = INF, curr = 0;
        for(int i = 0; i < n; ++i) {
            curr += nums[i];
            curr %= p;

            int need = (curr - target + p) % p;
            if(mp.count(need)) {
                minn = min(minn, i - mp[need]);
            }

            mp[curr] = i;
        }

        return minn == INF ? -1 : minn;
    }
};
