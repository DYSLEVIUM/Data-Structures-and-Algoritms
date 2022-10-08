class Solution {
public:
    bool judgeCircle(string moves) {
        int dx = 0, dy = 0;
        for(auto &move : moves) {
            dx += (move == 'R' ? 1 : 0) + (move == 'L' ? -1 : 0);
            dy += (move == 'U' ? 1 : 0) + (move == 'D' ? -1 : 0);
        }

        return !dx && !dy;
    }
};
