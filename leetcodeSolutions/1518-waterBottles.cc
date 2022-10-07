// https://leetcode.com/problems/water-bottles/solutions/743227/c-one-liner-0-ms-faster-than-100-00/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};

class Solution1 {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = 0, extras = 0;
        while(numBottles) {
            cnt += numBottles; // filled
            numBottles += extras; // empty
            extras = numBottles % numExchange; // new empty
            numBottles /= numExchange; // new filled
        }
        return cnt;
    }
};
