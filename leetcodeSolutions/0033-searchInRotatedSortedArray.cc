class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      
      int lo = 0, hi = n - 1;
      while(lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        
        if(nums[mid] == target) return mid;
        
        //  is the left half sorted?
        if(nums[lo] <= nums[mid]) { //  there is a check with equality also, check test case [-3, 1]
          //  does the target lie in the first half?
          if(target >= nums[lo] && target < nums[mid]) hi = mid - 1;
          else lo = mid + 1;
        } 
        //  if the left half is not sorted, the right half is definately sorted, otherwise there is a contradition of it not being a rotated sorted array
        else{
          //  does the target lie in the second half?
          if(target > nums[mid] && target <= nums[hi]) lo = mid + 1;
          else hi = mid - 1;
        }
      }
      
      return -1;
    }
};
