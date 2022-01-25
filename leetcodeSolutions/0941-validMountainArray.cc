class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
      int n = arr.size();
      
      if(n<3) return false;

      int dec_start = 0;
      
      for(int i=0;i<n-1;++i){
        if(arr[i]>=arr[i+1]){
          if(arr[i]==arr[i+1]) return false;
          dec_start = i;
          break;
        }
      }
      
      if(dec_start==0) return false;
      
      for(int i=dec_start+1;i<n-1;++i){
        if(arr[i]<=arr[i+1]) return false;
      }
      
      return true;
    }
};
