// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         cin.tie(nullptr)->sync_with_stdio(false);
        
//         int n = nums.size();

//         int ans = 0;
//         for(int i = 0; i < n - 2; ++i) {
//             int d = nums[i + 1] - nums[i];

//             int j = i + 2, cnt = 2;
//             while(j < n) {
//                 if(nums[j] - nums[j - 1] != d) {
//                     break;
//                 }
//                 ++j, ++cnt;
//             }

//             if(cnt < 3) {
//                 continue;
//             }

//             ans += ((cnt * (cnt + 1)) >> 1) - cnt - (cnt - 1); // total - size1 - size2
//             i = j - 2; // j - 2, as the last element may be the first to another sequence
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = nums.size();

        int ans = 0, cnt = 0;
        for(int i = 2; i < n; ++i) {
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                ++cnt;
                ans += cnt;
            } else {
                cnt = 0;
            }
        }

        return ans;
    }
};
