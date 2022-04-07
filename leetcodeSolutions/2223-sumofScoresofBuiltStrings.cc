class Solution {
public:
    vector<long long> z_function(const string& s) {
        int n = s.length();
        vector<long long> z(n);
        z[0] = n;//
        for(int i = 1, l = 0, r = 0; i < n; ++i) {
            if(i <= r) {
                z[i] = min(r - i + 1LL, z[i - l]);
            }
            
            while(z[i] + i < n && s[z[i] + 0] == s[z[i] + i]) ++z[i];
            
            if(i + z[i] - 1 > r) {
                l = i, r = z[i] + i - 1;    
            }
        }
        return z;
    }
    
    long long sumScores(string s) {
        auto z = z_function(s);
        long long ans = accumulate(z.begin(), z.end(), 0LL);
        
        return ans;
    }
};
