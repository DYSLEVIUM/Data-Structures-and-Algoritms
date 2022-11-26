class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();

        static constexpr int CHAR_SET = 10;
        vector<int> fa(CHAR_SET);

        int bulls = 0;
        for(int i = 0; i < n; ++i) {
            if(secret[i] == guess[i]) ++bulls;
            else ++fa[secret[i] - '0'];
        }

        int cows = 0;
        for(int i = 0; i < n; ++i) {
            if(secret[i] != guess[i]) cows += fa[guess[i] - '0']-- > 0;
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
