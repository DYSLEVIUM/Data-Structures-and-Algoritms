#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();

        int ans = 0;
        
        int xor1 = accumulate(nums1.begin(), nums1.end(), 0, bit_xor<int>());
        ans ^= n2 & 1 ? xor1 : 0;

        int xor2 = accumulate(nums2.begin(), nums2.end(), 0, bit_xor<int>());
        ans ^= n1 & 1 ? xor2 : 0;

        return ans;
    }
};
