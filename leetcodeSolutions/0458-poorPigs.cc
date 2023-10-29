// https://leetcode.com/problems/poor-pigs/solutions/94266/another-explanation-and-solution/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int slots = minutesToTest / minutesToDie + 1;
        // return ceil(log2(buckets) / log2(slots)); // logb(a) = logc a / logc b

        if(buckets <= 1) {
            return 0;
        }

        int ans = 1;
        int curr = slots;
        while(curr < buckets) {
            ++ans;
            curr *= slots;
        }

        return ans;
    }
};

/*
    pigs = log2(buckets) / log2(slots + 1);
    (slots + 1)^pigs = buckets
*/
