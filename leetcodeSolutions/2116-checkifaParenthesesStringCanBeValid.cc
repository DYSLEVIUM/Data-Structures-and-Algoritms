#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    bool canBeValid(const string & s, const string & locked) {
        const int n = s.size();

        if(n & 1) {
            return false;
        }

        int open = 0, unlocked = 0;
        for(int i = 0; i < n; ++i) {
            if(locked[i] == '0') {
                ++unlocked;
                continue;
            }

            if(s[i] == '(') {
                ++open;
            } else {
                if(open > 0) {
                    --open;
                } else if(unlocked > 0) {
                    --unlocked;
                } else {
                    return false;
                }
            }
        }

        // match remaining open with the unlocked;
        int balance = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(locked[i] == '0') {
                --balance, --unlocked;
            } else if(s[i] == '(') {
                ++balance, --open;
            } else if(s[i] == ')') {
                --balance;
            }

            if(balance > 0) {
                return false;
            }

            if(!unlocked && !open) {
                break;
            }
        }

        return open <= 0;
    }
};
