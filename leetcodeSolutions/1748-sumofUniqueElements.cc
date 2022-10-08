class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &num : nums) {
            ++mp[num];
        };

        int sum = 0;
        for(auto &[num, cnt] : mp) {
            if(cnt == 1) {
                sum += num;
            }
        }

        return sum;
    }
};
