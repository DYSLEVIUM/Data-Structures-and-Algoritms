class Solution {
public:
    int numTilings(int n) {        
        if(n <= 2) return n;
        
        const auto mod_add = [](const int& x, const int& y){
            const int MOD = 1e9 + 7;
            
            return ((x % MOD) + (y % MOD)) % MOD;
        };
        
        //  f signifies fully filled
        //  p signifies partially filled
        
        int f_prev = 1; //  at 1
        int f_curr = 2; //  at 2
        int p_curr = 1; //  at 2
        
        for(int i = 3; i < n + 1; ++i){
            int temp = f_curr;
            
            f_curr = mod_add(mod_add(mod_add(f_curr, f_prev), 2 * p_curr) , 0); //  make full board by adding a vertical and adding 2 horizontal to i-1 and a L piece (multiply by 2 due to horizontal symmetry) to partial board
            p_curr = mod_add(mod_add(p_curr, f_prev), 0);   //  make another partial board by adding a horizontal piece
            
            f_prev = temp;
        }
        
        return f_curr;
    }
};
