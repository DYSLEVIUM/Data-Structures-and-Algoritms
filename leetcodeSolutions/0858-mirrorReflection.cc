class Solution {
public:
    // https://leetcode.com/problems/mirror-reflection/discuss/146336/Java-solution-with-an-easy-to-understand-explanation
    int mirrorReflection(int p, int q) {
        while(p % 2 == 0 && q % 2 == 0) {
            p >>= 1;
            q >>= 1;
        }
        
        if((p & 1) && q % 2 == 0) {
            return 0;
        } else if((p & 1) && (q & 1)) {
            return 1;
        } else if (p % 2 == 0 && (q & 1)){
            return 2;
        }
        
        return -1;
    }
};
