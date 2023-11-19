class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = nums.size();

        sort(nums.begin(), nums.end());
    
        int ans = 0;
        unordered_set<int> se;
        for(int i = 0; i < n; ++i) {
            if(nums[i] != nums[0]) {
                ans += se.size() - se.count(nums[i]); // subtracting as, if the element is repeated, we do not want to perform an illegal operation
            }
            se.insert(nums[i]);
        }

        return ans;
    }
};
