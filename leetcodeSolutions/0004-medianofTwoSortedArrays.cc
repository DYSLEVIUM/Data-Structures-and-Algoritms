class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        if(n1 > n2) {
            swap(nums1, nums2);
            swap(n1, n2);
        }
        
        int half = total >> 1;
        
        //  we try to find a valid partition point in nums1, such that, other elements are taken from nums2
        //  divide and conquer using binary search of the partition point
        
        //  mid can be negative => we take no elements from nums1, similar reasoning can be given for other
        int nums1_left;
        int nums1_right;

        int nums2_left;
        int nums2_right;
        
        int lo = 0, hi = n1 - 1;
        while(1) {
            int mid = lo + ((hi - lo) >> 1);
            
            int other = half - mid - 2;
            
            nums1_left = mid < 0 ? INT_MIN : nums1[mid];
            nums1_right = mid + 1 >= n1 ? INT_MAX : nums1[mid + 1];
            
            nums2_left = other < 0 ? INT_MIN : nums2[other];
            nums2_right = other + 1 >= n2 ? INT_MAX : nums2[other + 1];
            
            if(nums1_left <= nums2_right && nums2_left <= nums1_right) {
                break;
            } else if (nums1_left > nums2_right) {
                //  decrease the biggest element in nums1
                hi  = mid - 1;
            } else {
                //  increase the smallest element in nums1
                lo = mid + 1;
            }
        }
        
        if(total & 1) {
            return min(nums1_right, nums2_right);
        }
        
        return (max(nums1_left, nums2_left) + min(nums1_right, nums2_right)) / 2.0;
    }
};
