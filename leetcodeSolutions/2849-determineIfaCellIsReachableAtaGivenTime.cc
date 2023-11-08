class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx - fx), dy = abs(sy - fy);

        // impossible case
        if(!dx && !dy && t == 1) {
            return false;
        }

        return t >= max(dx, dy);
    }
};
