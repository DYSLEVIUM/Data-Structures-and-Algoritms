class Solution {
public:
    int commonFactors(int a, int b) {
        int minn = min(a, b);
        int cnt = 0;
        for(int i = 1; i * i <= minn; ++i) {
            if(minn % i != 0) {
                continue;
            }

            int other = minn / i;
            cnt += (a % i == 0) && (b % i == 0);
            cnt += (i != other) && (a % other == 0) && (b % other == 0);
        }
        return cnt;
    }
};
