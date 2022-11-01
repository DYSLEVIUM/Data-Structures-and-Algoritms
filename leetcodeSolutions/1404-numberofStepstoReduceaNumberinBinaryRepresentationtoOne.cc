class Solution {
public:
    int numSteps(string s) {
        int n = s.size();

        int ans = 0, carry = 0;
        for(int i = n - 1; i > 0; --i) {
            if(s[i] == '1') {
                if(carry) {
                    ++ans; // divide by 2
                } else {
                    ++carry;
                    ans += 2; // add 1 and divide
                }
            } else {
                if(carry) {
                    s[i] = '1';
                    carry = 0;
                    ++i; // will be handled in next iteration
                } else {
                    ++ans; // divide by 2
                }
            }
        }

        if(carry) ++ans;

        return ans;
    }
};
