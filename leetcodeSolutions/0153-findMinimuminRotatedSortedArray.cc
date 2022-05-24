class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) {
            return nums.front();
        }

        //  making sure at least one rotation exists if the vector is not sorted
        if(nums.front() < nums.back()) {
            return nums.front();
        }
        
        int lo = 0, hi = n - 1;
        while(lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            
            //  checking if mid is the critical point
            {
                if(nums[mid] > nums[mid + 1]) {
                    return nums[mid + 1];
                }

                if(nums[mid] < nums[mid - 1]) {
                    return nums[mid];
                }
            }
          
            
            if(nums[mid] > nums[0]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        //  unreachable code
        return -1;
    }
};
