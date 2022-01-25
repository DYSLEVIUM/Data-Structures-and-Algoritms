class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
      int cnt = 0;
      
      int n = arr.size();
      
      auto check_condition = [&](const int& i, const int& j, const int& k){
        return abs(arr[i]-arr[j]) <= a && abs(arr[j]-arr[k]) <= b && abs(arr[i]-arr[k]) <= c;
      };
      
      for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
          for(int k=j+1;k<n;++k){
            cnt+=check_condition(i,j,k);
          }
        }
      }
      
      return cnt;
    }
};
