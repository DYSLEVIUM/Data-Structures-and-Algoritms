class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
      int n = arr.size();
      sort(arr.begin(), arr.end());
      
      int minn = INT_MAX;
      for(int i = 1; i < n; ++i) {
        minn = min(minn, arr[i] - arr[i - 1]);
      }
      
      vector<vector<int>> ans;
      for(int i = 1; i < n; ++i) {
        if(arr[i] - arr[i - 1] == minn) {
          ans.push_back({arr[i - 1], arr[i]});
        }
      }
      
      return ans;
    }
};
