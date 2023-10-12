/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(const int& target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        auto find_peak_element = [&](){
            int lo = 0, hi = n - 1;
            while(lo < hi) {
                int mid = lo + ((hi - lo) >> 1);
                if(mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }

            return lo;
        };
        
        auto bs = [&](int st, int ed){
            bool asc = mountainArr.get(st) < mountainArr.get(ed);

            while(st <= ed) {
                int mid = st + ((ed - st) >> 1);
                int mid_val = mountainArr.get(mid);

                if(mid_val == target) {
                    return mid;
                }

                if (asc) {
                    if (mid_val < target) {
                        st = mid + 1;
                    } else {
                        ed = mid - 1;
                    }
                } else {
                    if (mid_val < target) {
                        ed = mid - 1;
                    } else {
                        st = mid + 1;
                    }
                }
            }

            return -1;
        };

        int peak_element = find_peak_element();

        // check on the left side
        int le = bs(0, peak_element);
        if(le != -1) {
            return le;
        }

        // check on right side
        return bs(peak_element + 1, n - 1);
    }
};
