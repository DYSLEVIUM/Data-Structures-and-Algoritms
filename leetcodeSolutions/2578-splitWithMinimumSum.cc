class Solution {
public:
    int splitNum(int num) {
        string sNum = to_string(num);
        sort(sNum.begin(), sNum.end());

        int n = sNum.size();

        int n1 = 0, n2 = 0;
        for(int i = 0, j = 1; i < n; i += 2, j += 2) {
            n1 = n1 * 10 + (sNum[i] - '0');
            if(j < n) n2 = n2 * 10 + (sNum[j] - '0');
        }

        return n1 + n2;
    }
};
