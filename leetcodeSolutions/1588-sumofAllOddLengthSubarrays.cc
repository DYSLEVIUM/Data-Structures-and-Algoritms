class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
      int sum = 0;
      
      int n = arr.size();

//       for(int l_ptr=0;l_ptr<n;++l_ptr){
//         for(int r_ptr=l_ptr;r_ptr<n;r_ptr+=2){
//             sum += pre[r_ptr]-(l_ptr<1?0:pre[l_ptr-1]);
//         }
//       }
      
//       return sum;
      
      for(int i=0;i<n;++i){
        sum+=(((i+1)*(n-i)+1)/2)*arr[i];
      }
      
      return sum;
    }
};
