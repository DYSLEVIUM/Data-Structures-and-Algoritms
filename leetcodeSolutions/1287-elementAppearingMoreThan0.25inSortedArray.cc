class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
      int n = arr.size();
      
      int cap = 0.25 * n;
      for(int i = 0; i < n; ++i) {
        int j = i + 1, cnt = 1;
        while(j < n && arr[j] == arr[i]) {
          ++cnt, ++j;
        }
        if(cnt > cap) return arr[i];
        i = j - 1;
      }
      
      return 0;
    }
};
