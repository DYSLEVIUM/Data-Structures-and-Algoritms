class Solution {
public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> num_to_pow;
        num_to_pow[1] = 0;
        auto get_pow = [&num_to_pow](const auto &get_pow, const int &x){
            if(num_to_pow.find(x) != num_to_pow.end()) {
                return num_to_pow[x];
            }
            
            int steps = (x & 1) ? get_pow(get_pow, 3 * x + 1) : get_pow(get_pow, x >> 1);
            return num_to_pow[x] = 1 + steps;
        };
        
        int n = hi - lo + 1;
        vector<int> power(n);
        iota(power.begin(), power.end(), lo);
        sort(power.begin(), power.end(), [&get_pow](const int &lhs, const int &rhs){
            if(get_pow(get_pow, lhs) == get_pow(get_pow, rhs)) {
                return lhs < rhs;
            }
            
            return get_pow(get_pow, lhs) < get_pow(get_pow, rhs);
        });
        
        return power[k - 1];
    }
};
