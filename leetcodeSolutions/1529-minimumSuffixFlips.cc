class Solution {
public:
    int minFlips(string target) {
        reverse(target.begin(), target.end());
        int cnt = 0;
        char curr_target = '0';
        while(target != "") {
            if(target.back() != curr_target) {
                ++cnt;
                curr_target ^= '0' ^ '1';
            }
            target.pop_back();
        }

        return cnt;
    }
};
