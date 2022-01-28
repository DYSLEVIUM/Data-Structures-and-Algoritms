class Solution {
public:
    int largestAltitude(vector<int>& gains) {
      int maxi = 0;
      int curr = 0;
      
      for(auto& gain: gains){
        maxi = max(maxi, curr+gain);
        curr+=gain;
      }
      
      return maxi;
    }
};
