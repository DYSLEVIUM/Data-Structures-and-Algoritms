class Solution {
public:
    int maxLengthBetweenEqualCharacters(const string & s) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int ans = -0x3f3f3f;
        unordered_map<char, int> mp_f, mp_s;
        for(int i = 0; const char & ch : s) {
            if(!mp_f.count(ch)) {
                mp_f[ch] = i;
            }
            mp_s[ch] = i;

            ans = max(ans, mp_s[ch] - mp_f[ch] - 1);
            ++i;
        }

        return ans;
    }
};
