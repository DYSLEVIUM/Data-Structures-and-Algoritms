class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int lo = 0, hi = n - 1;
        while(lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            
            if(nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else if(nums[mid] < nums[hi]) {
                hi = mid;
            } else {
                if (h && nums[hi - 1] > nums[hi]) { //  checking if this is the critical point
                    lo = hi;
                    break;
                }
                hi--;
            }
        }
        
        return nums[lo];
    }
};
