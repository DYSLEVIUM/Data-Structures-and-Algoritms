class Solution {
public:
    int minOperations(const string & s) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int cnt01 = 0;
        char should_be = '0';
        for(const char & c : s) {
            cnt01 += c != should_be;
            should_be ^= '0' ^ '1';
        }

        int cnt10 = s.size() - cnt01;

        return min(cnt01, cnt10);
    }
};
