class Solution {
public:
    long long smallestNumber(long long num) {
        cin.tie(nullptr)->sync_with_stdio(false);

        bool is_neg = num < 0;
        if(is_neg) {
            num *= -1;
        }

        string s = to_string(num);
        sort(s.begin(), s.end());

        if(is_neg) {
            reverse(s.begin(), s.end());
        }

        if(s[0] == '0') {
            for(int i = 1; i < s.size(); ++i) {
                if(s[i] != '0') {
                    swap(s[i], s[0]);
                    break;
                }
            }
        }

        long long ans = stoll(s);
        if(is_neg) {
            ans *= -1;
        }

        return ans;
    }
};
