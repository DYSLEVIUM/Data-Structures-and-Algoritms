class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        vector<int> diff(n);
        for(int i = 0; const int & num : nums) {
            ++mp[num];
            diff[i++] = mp.size();
        }

        mp.clear();
        reverse(nums.begin(), nums.end());

        for(int i = n - 1; const int & num : nums) {
            diff[i] -= mp.size();
            ++mp[num], --i;
        }

        return diff;
    }
};
