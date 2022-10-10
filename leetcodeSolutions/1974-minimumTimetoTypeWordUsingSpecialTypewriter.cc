class Solution {
public:
    int minTimeToType(string word) {
        int ans = word.size(); // time to press letter
        char prev = 'a';
        for(auto &ch : word) {
            ans += min(abs(prev - ch), 26 - abs(prev - ch));
            prev = ch;
        }

        return ans;
    }
};
