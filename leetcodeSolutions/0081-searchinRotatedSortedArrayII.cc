class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int lo = 0, hi = n - 1;
        while(lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            
            if(nums[mid] == target) {
                return true;
            }
            
            //  we will always check on the sorted side 
            if(nums[lo] < nums[mid]) {
                //  does the target lie in the sorted range ?
                if(target >= nums[lo] && target < nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            } else if(nums[lo] > nums[mid]) {
                //  does the target lie in the sorted range ?
                if(target > nums[mid] && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            } else {
                //  edge case, when duplicates are allowed
                ++lo;
            }
        }
        
        return false; 
    }
};
