class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1, nums2);
        unordered_multiset<int> se(nums1.begin(), nums1.end());
        
        vector<int> ans;
        for(int & num : nums2) {
            if(se.count(num)) ans.push_back(num), se.erase(se.find(num));
        }

        return ans;
    }
};
