class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int maxx = INT_MAX, minn = INT_MAX;
      
      for(auto& num:nums){
        if(num<=minn) minn = num;
        else if(num<=maxx) maxx = num;
        else return true;
      }
      
      return false;
    }
};
