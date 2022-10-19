class Solution {
public:
    bool hasAlternatingBits(const int &n) {
        auto check = [&](const int &init){
            int num = n, should_be = init;
            while(num) {
                if((num & 1) != should_be) return false;
                should_be ^= 1 ^ 0;
                num >>= 1;
            }
            return true;
        };
        return check(0) || check(1);
    }
};
