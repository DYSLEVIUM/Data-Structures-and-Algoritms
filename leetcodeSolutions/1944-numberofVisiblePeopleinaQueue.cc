class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
      int n = heights.size();
      
      vector<int> ans(n);
      
      //  how many next greater elements are there
      
      //  monotonic stack (v1)
//       stack<int> st;
//       for(int i = 0; i < n; ++i) {
//         while(!st.empty() && heights[st.top()] <= heights[i]) {
//           ++ans[st.top()];
//           st.pop();
//         }
        
//         //  the just next person's height doesn't matter
//         if(!st.empty()) {
//           ++ans[st.top()];
//         }
        
//         st.push(i);
//       }
      
      //  monotonic stack (v2)
      stack<int> st;
      for(int i = n - 1; i >= 0; --i) {
        while(!st.empty() && heights[st.top()] <= heights[i]) {
          ++ans[i];
          st.pop();
        }
        
        //  the just next person's height doesn't matter
        ans[i] += !st.empty();
        
        st.push(i);
      }
      
      return ans;
    }
};
