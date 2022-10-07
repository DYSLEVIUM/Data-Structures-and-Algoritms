class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string balloon = "balon";

        unordered_map<char, int> mp;
        for(auto &ch : balloon) {
            mp[ch] = 0;
        }

        for(auto &ch : text) {
            if(balloon.find(ch) != string::npos) {
                ++mp[ch];
            }
        }

        int minn = INT_MAX;
        for(auto &[ch, cnt] : mp) {
            if(ch == 'l' || ch == 'o') {
                cnt >>= 1;
            }
            minn = min(minn, cnt);
        }

        return minn;
    }
};
