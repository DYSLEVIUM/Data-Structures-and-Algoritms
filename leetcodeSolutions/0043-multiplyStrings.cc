class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
      
        // smaller number on the bottom
        if(n1 < n2) swap(num1, num2), swap(n1, n2);

        auto mult = [](string num, const char & digit, int place){
            reverse(num.begin(), num.end());

            string ans;
            int carry = 0;
            for(int i = 0; i < num.size(); ++i) {
                int tot = (num[i] - '0') * (digit - '0') + carry;
                ans += to_string(tot % 10);
                carry = tot / 10;
            }
            if(carry) ans += to_string(carry);

            // remove leading zeroes (here its reversed)
            while(!ans.empty() && ans.back() == '0') ans.pop_back();

            reverse(ans.begin(), ans.end());

            while(place--) ans += "0";
            return ans.empty() ? "0" : ans;
        };

        auto add = [](string x, string y){
            reverse(x.begin(), x.end());
            reverse(y.begin(), y.end());

            string ans;

            int p1, p2, carry;
            p1 = p2 = carry = 0;
            while(p1 < x.size() || p2 < y.size()) {
                int tot = (p1 == x.size() ? 0 : x[p1++] - '0') + (p2 == y.size() ? 0 : y[p2++] - '0') + carry;
                ans += to_string(tot % 10);
                carry = tot / 10;
            }

            if(carry) ans += to_string(carry);

            // remove leading zeroes (here its reversed)
            while(!ans.empty() && ans.back() == '0') ans.pop_back();

            reverse(ans.begin(), ans.end());
            return ans.empty() ? "0" : ans;
        };

        string ans = "0";
        for(int i = n2 - 1; i >= 0; --i) ans = add(ans, mult(num1, num2[i], n2 - 1 - i));
        return ans;
    }
};
