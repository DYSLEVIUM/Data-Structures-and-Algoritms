class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        auto rev = [](int n){
            int res = 0;
            while(n) {
                res = res * 10 + n % 10;
                n /= 10;
            }
            return res;
        };

        for(int i = 0; i <= num; ++i) {
            if(i + rev(i) == num) {
                return true;
            }
        }

        return false;
    }
};
