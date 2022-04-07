vector<int> z_function(const string& s) {
        int n = s.length();
        vector<int> z(n);
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
