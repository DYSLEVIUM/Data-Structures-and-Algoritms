class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> se;
        int ans = -1;
        for(auto &num : nums) {
            if(se.count(-num)) {
                ans = max(ans, abs(num));
            }
            se.insert(num);
        }

        return ans;
    }
};
