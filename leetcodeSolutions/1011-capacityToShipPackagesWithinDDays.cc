class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        auto check = [&](const int & x){
            int curr = 0, cnt = 0;
            for(auto & weight : weights) {
                curr += weight;
                if(curr > x) {
                    curr = weight;
                    ++cnt;
                }
            }
            cnt += !!curr;
            return cnt <= days;
        };

        int lo = *max_element(weights.begin(), weights.end()), hi = 0x3f3f3f3f;
        while(lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if(check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
