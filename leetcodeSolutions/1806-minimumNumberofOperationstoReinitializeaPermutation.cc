class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> orgi_perm(n);
        iota(orgi_perm.begin(), orgi_perm.end(), 0);

        int cnt = 0;
        vector<int> perm = orgi_perm, arr(n);
        do {
            for(int i = 0; i < n; ++i) {
                if(i & 1) {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                } else {
                    arr[i] = perm[i / 2];
                }
            }

            ++cnt;
            perm = arr;
        } while(arr != orgi_perm);

        return cnt;
    }
};
