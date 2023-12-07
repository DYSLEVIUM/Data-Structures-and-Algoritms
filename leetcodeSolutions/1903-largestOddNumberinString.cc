class Solution {
public:
    string largestOddNumber(string num) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int i = num.size();
        while(i--) {
            if((num[i] - '0') & 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
