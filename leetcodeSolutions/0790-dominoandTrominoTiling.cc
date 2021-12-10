class Solution {
public:
    int numTilings(int n) {        
        if(n <= 2) return n;
        
        const auto mod_add = [](const int& x, const int& y){
            const int MOD = 1e9 + 7;
            
            return ((x % MOD) + (y % MOD)) % MOD;
        };
        
        int f_prev = 1;
        int f_curr = 2;
        int p_curr = 1;
        
        for(int i = 3; i < n + 1; ++i){
            int temp = f_curr;
            
            f_curr = mod_add(mod_add(mod_add(f_curr, f_prev), 2 * p_curr) , 0);
            p_curr = mod_add(mod_add(p_curr, f_prev), 0);
            
            f_prev = temp;
        }
        
        return f_curr;
    }
};
