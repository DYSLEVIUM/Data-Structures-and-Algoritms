class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());

        int score = 0, maxx = 0;
        int lo = 0, ri = n - 1;
        while(lo <= ri) {
            if(power >= tokens[lo]) {
                power -= tokens[lo++];
                ++score;
            } else {
                if(score > 0) { // score >= 1
                    power += tokens[ri];
                    --score;
                }
                --ri;
            }
            maxx = max(maxx, score);
        }

        return maxx;
    }
};
