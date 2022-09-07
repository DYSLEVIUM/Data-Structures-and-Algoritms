class Solution {
public:
    int maximumSum(vector<int>& arr) {
      int n = arr.size();
      
      int ignored = 0, not_ignored = arr[0];
      int ans = not_ignored; // subarray should have at least 1 element
      for(int i = 1; i < n; ++i) {
        ignored = max(not_ignored, ignored + arr[i]); // if we want to ignore the current element, we must have not ignored previously, else we have to take the current number
        
	      not_ignored = max(arr[i], arr[i] + not_ignored); // if we don't want to ignore the current element, we can start the subarray from this position or take the element
        
        ans = max({ans, ignored, not_ignored});
      }
      
      return ans;
    }
};
