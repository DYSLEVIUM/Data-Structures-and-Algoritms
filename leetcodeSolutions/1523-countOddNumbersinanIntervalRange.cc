class Solution {
public:
    int countOdds(int low, int high) {
        auto odd = [](const int &x){
            if(x <= 0) {
                return 0;
            }
            
            return x / 2 + (x & 1);
        };
        return odd(high) - odd(low - 1);
    }
};
