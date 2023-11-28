class Solution {
public:
    int numberOfWays(string corridor) {
        cin.tie(nullptr)->sync_with_stdio(false);

        constinit static int MOD = 1e9 + 7;

        int n = corridor.size();

        int cnt = 1, seats = 0, prev = -1;
        for(int i = 0; i < n; ++i) {
            if(corridor[i] == 'P') {
                continue;
            }

            ++seats;
            if(seats == 2) {
                prev = i;
                seats = 0;
            } else if (prev != -1) {
                cnt *= (i - prev);
                cnt %= MOD;
            }
        }

        if(seats == 1 || prev == -1) {
            return 0;
        }

        return cnt;
    }
};
