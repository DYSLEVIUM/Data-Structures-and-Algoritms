class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int maxx = INT_MAX, minn = INT_MAX;
      
      //  we will find the minimum number and the just greater number, if it is not from the max or min, that means it is the middle element of those two elements
      for(auto& num:nums){
        if(num<=minn) minn = num;
        else if(num<=maxx) maxx = num;
        else return true;
      }
      
      return false;
    }
};
