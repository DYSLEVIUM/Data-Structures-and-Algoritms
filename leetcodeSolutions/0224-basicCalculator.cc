class Solution {
public:
    int calculate(string s) {
        int n = s.size();

        int ans = 0, sign = 1;
        for(int i = 0; i < n; ++i) {
            if(isdigit(s[i])) {
                int num = 0;
                while(i < n && isdigit(s[i])) num = num * 10 + (s[i++] - '0');
                --i;
                ans += num * sign;
            } else if(s[i] == '+') sign = 1;
            else if(s[i] == '-') sign = -1;
            else if(s[i] == '(') {
                string te;
                int j = i + 1, open = 1;
                while(j < n && open) {
                    open += s[j] == '(';
                    open -= s[j] == ')';
                    te += s[j++];
                }
                te.pop_back(); // remove the last close bracket
                ans += sign * calculate(te);
                i = j - 1;
            }
        }
        return ans;
    }
};
