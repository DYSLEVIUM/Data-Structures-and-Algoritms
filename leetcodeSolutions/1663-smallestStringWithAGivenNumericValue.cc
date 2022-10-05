class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        while(n) {
            int lo = 1, hi = 26;
            while(lo < hi) {
                int mid = lo + ((hi - lo) >> 1);
                if(mid + (n - 1) * 26 < k) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }

            char curr = lo + 'a' - 1;
            ans += curr, k-= lo, --n;
        }

        return ans;
    }
};

class Solution1 {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        while(n) {
            char curr = 'a';
            int curr_val = curr - 'a' + 1;
            while(curr_val + (n - 1) * 26 < k) {
                ++curr, ++curr_val;
            }

            ans += curr;
            k -= curr_val;
            --n;
        }

        return ans;
    }
};
