class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        int xorr = 0;
        for(int i = 0; i < n; ++i) xorr ^= (i + 1) ^ nums[i];

        int lsb = xorr & -xorr; // idea from fenwick tree

        int x = 0, y = 0;
        for(int & num : nums) {
            if(num & lsb) x ^= num;
            else y ^= num;
        }

        for(int i = 1; i <= n; ++i) {
            if(i & lsb) x ^= i;
            else y ^= i;
        }

        int cnt = 0;
        for(int & num : nums) cnt += num == x;
        
        if(cnt == 0) swap(x, y);

        return {x, y};
    }
};
