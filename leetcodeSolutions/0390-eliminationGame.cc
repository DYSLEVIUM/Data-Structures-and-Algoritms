// https://leetcode.com/problems/elimination-game/solutions/355060/c-simple-explanation-with-pictures/
class Solution {
public:
    int lastRemaining(int n) {
        int curr = 1, step = 1;
        int dir = 1;
        while(n > 1) {
            if(dir) curr += step;
            else curr += n % 2 ? step : 0;
            
            // one cycle complete, back and forth
            step <<= 1;
            n >>= 1;
            dir = 1 - dir;
        }

        return curr;
    }
};
