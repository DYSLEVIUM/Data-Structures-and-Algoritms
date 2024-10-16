#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    long long minimumSteps(string & s) {
        const int n = s.size();
        
        long long cnt = 0;

        int whitePos = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] != '0') {
                continue;    
            }

            cnt += i - whitePos;
            ++whitePos;
        }

        return cnt;
    }
};
