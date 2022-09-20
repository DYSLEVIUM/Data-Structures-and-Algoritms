class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
      // find the longest common substring
      int n1 = nums1.size(), n2 = nums2.size();
      
      int ans = 0;
      vector<int> prev(n2 + 1), curr(n2 + 1);
      for(int i = 0; i < n1 + 1; ++i) {
        for(int j = 0; j < n2 + 1; ++j) {
          if(!i || !j) {
            curr[j] = 0;
          } else {
            if(nums1[i - 1] == nums2[j - 1]) {
              curr[j] = 1 + prev[j - 1];
            } else {
              curr[j] = 0;
            }
            
            ans = max(ans, curr[j]);
          }
        }
        prev = curr;
      }
      
      return ans;
    }
};
