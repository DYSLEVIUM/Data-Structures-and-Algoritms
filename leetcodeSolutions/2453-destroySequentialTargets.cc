class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        /* let the final value be x -> nums[i] = x + c * space
                                    => (nums[i] - x) / space = c ; c is an non-negative integer
            
            So, (nums[i] - x) % space = 0; as c is a integer
                => nums[i] % space = x % space
            
            So, we just need to get the number with max occurence, and the smallest number in that group
        */
        constexpr int INF = 0x3f3f3f3f;
        
        int maxx = -INF;
        unordered_map<int, int> mp;
        for(int & num : nums) {
            int mod = num % space;
            maxx = max(maxx, ++mp[mod]);
        }

        int ans = INF;
        for(int & num : nums) {
            int mod = num % space;
            if(maxx == mp[mod]) ans = min(ans, num);
        }
        return ans;
    }
};
