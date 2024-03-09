#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int getCommon(const vector<int> & nums1, const vector<int> & nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        int p1 = 0, p2 = 0;
        while(p1 < n1 && p2 < n2) {
            if(nums1[p1] == nums2[p2]) {
                return nums1[p1];
            }

            if(nums1[p1] < nums2[p2]) {
                ++p1;
            } else {
                ++p2;
            }
        }

        return -1;
    }
};
