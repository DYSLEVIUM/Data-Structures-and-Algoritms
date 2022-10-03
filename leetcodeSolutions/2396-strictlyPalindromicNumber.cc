class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        auto check = [](const vector<int> &digits){
            int n = digits.size();
            for(int i = 0; i < n / 2; ++i) {
                if(digits[i] != digits[n - 1 - i]) {
                    return false;
                }
            }
            return true;
        };

        auto con = [](int n, const int &b){
            vector<int> ans;
            while(n) {
                ans.push_back(n % b);
                n /= b;
            }
            return vector(ans.rbegin(), ans.rend());
        };

        for(int b = 2; b <= n - 2; ++b) {
            if(!check(con(n, b))) {
                return false;
            }
        }

        return true;
    }
};
