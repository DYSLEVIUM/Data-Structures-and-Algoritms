class Solution {
public:
    int binaryGap(int n) {
        int pos1 = -1, iter = 0, maxx = INT_MIN;
        while(n) {
            if(n & 1) {
                if(pos1 == -1) {
                    pos1 = iter;
                } else {
                    maxx = max(maxx, iter - pos1);
                    pos1 = iter;
                }
            }

            n >>= 1, ++iter;
        }

        return maxx == INT_MIN ? 0 : maxx;
    }
};
