class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      int n = arr.size(), total = 0;
      for(int i = 0; i < k - 1; ++i) {
        total += arr[i];
      }
      
      int ans = 0;
      for(int i = k - 1; i < n; ++i) {
        total += arr[i];
        ans += (total / k) >= threshold;
        total -= arr[i - k + 1];
      }
      
      return ans;
    }
};
