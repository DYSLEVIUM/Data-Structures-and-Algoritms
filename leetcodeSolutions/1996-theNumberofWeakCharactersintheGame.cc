class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
      int n = properties.size();
      sort(properties.begin(), properties.end(), [](const vector<int> &a, const vector<int> &b){
        // we will greedily check the smaller defense, as it may provide a answer
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
      });
      
      int maxx = INT_MIN, ans = 0;
      for(int i = n - 1; i >= 0; --i) {
        ans += properties[i][1] < maxx;
        maxx = max(maxx, properties[i][1]);
      }
      
      return ans;
    }
};
