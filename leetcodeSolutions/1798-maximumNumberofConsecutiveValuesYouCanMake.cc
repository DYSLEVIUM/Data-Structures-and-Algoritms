class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());

        int can_make = 0;
        for(auto & coin : coins) {
            // can_make - 1 is the sum that we can make
            // coin should always come inside the range of [0, can_make], else we will not be able to make coin as a sum
            if(coin - can_make > 1) break;
            can_make += coin;
        }

        return can_make + 1;
    }
};
