class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        
        vector<vector<int>> numss(2), targett(2);
        for(int i = 0; i < n; ++i) {
            numss[nums[i] & 1].push_back(nums[i]);
            targett[target[i] & 1].push_back(target[i]);
        }

        auto make_equal = [](vector<int> & nums, vector<int> & tar){
            int n = nums.size();
            long long cnt = 0;
            for(int i = 0; i < n; ++i) cnt += abs(nums[i] - tar[i]);
            return cnt >> 1; // we are adding by 2, so steps will half of that
        };
   
        long long ans = make_equal(numss[0], targett[0]) + make_equal(numss[1], targett[1]);       
        return ans >> 1; // dividing by 2, as we are counting twice
    }
};
