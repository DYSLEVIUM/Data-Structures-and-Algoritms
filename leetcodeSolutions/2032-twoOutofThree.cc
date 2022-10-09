class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        bool cnt[3][101] = {};
        for(auto &num : nums1) {
            cnt[0][num] = true;
        }

        for(auto &num : nums2) {
            cnt[1][num] = true;
        }

        for(auto &num : nums3) {
            cnt[2][num] = true;
        }

        vector<int> ans;
        for(int i = 1; i < 101; ++i) {
            if(cnt[0][i] + cnt[1][i] + cnt[2][i] > 1) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
