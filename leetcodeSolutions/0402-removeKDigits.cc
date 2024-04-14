#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    string removeKdigits(const string & num, int k) {
        string ans;
        for(const char & digit : num) {
            while (!ans.empty() && k && ans.back() > digit) {
                ans.pop_back();
                --k;
            }
            ans += digit;
        }

        // at last, if we have still have k, we have a monotonic array(stack); remove from the last
        while(k-- && !ans.empty()) {
            ans.pop_back();
        }

        size_t pos = ans.find_first_not_of('0');
        
        return pos == string::npos ? "0" : ans.substr(pos);
    }
};
