class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int n1 = nums1.size();
      int n2 = nums2.size();
      
      unordered_map<int, int> mp;
      for(int i = 0; i < n1; ++i) {
        mp[nums1[i]] = i;
      }
      
      vector<int> ans(n1);
      
      stack<int> st;
      for(int i = n2 - 1; i >= 0; --i) {
        while(!st.empty() && nums2[i] >= st.top()) {
          st.pop();
        }
        
        if(mp.find(nums2[i]) != mp.end()) {
          if(st.empty()) {
            ans[mp[nums2[i]]] = -1;
          } else {
            ans[mp[nums2[i]]] = st.top();
          }
        }
        st.push(nums2[i]);
      }
      
      return ans;
    }
};
