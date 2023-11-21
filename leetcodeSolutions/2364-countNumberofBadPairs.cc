// class Solution {
// public:
//     long long countBadPairs(vector<int>& nums) {
//         cin.tie(nullptr)->sync_with_stdio(false);

//         int n = nums.size();

//         long long ans = 0;
//         unordered_map<int, int> mp;
//         for(int i = 0; i < n; ++i) {
//             int key = i - nums[i];
//             ans += mp[key]++;
//         }

//         long long total_pairs = ((n * (n - 1LL)) >> 1); // nC2

//         return total_pairs - ans;
//     }
// };

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = nums.size();

        long long ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            int key = i - nums[i];
            ans += i - mp[key]++; // i is total pairs till this iteration
        }

        return ans;
    }
};
