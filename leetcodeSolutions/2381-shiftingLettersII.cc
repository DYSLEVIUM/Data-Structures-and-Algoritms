#pragma GCC optmize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    string shiftingLetters(const string & s, const vector<vector<int>>& shifts) {
        static constinit const int CHAR_SET = 26;

        const int n = s.size();

        vector<int> deltas(n + 1);
        for(const vector<int> & shift: shifts) {
            const int & start = shift[0], & end = shift[1];

            int dir = shift[2];
            dir <<= 1, --dir; // making {0 or 1} to {-1 or 1}

            deltas[start] += dir, deltas[end + 1] -= dir;
        }

        for(int i = 0; i < n + 1; ++i) {
            deltas[i] += CHAR_SET + (i == 0 ? 0 : deltas[i - 1]);
            deltas[i] %= CHAR_SET;
        }

        string ans = s;
        for(int i = 0; char & ch: ans) {
            ch -= 'a';

            ch += deltas[i++] + CHAR_SET;
            ch %= CHAR_SET;
            
            ch += 'a';
        }

        return ans;
    }
};
