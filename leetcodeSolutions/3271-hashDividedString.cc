#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    string stringHash(const string & s, const int & k) const {
        const int n = s.size();
        const int OFFSET = 'a' * k;

        const auto hash_fn = [](const int & sum){
            return sum % 26;
        };

        string hash;
        hash.reserve(n / k);
        
        for(int i = 0; i < n; i += k) {
            int sum = 0;
            for(int j = 0; j < k; ++j) {
                sum += s[i + j];
            }
            
            hash.push_back(
                hash_fn(sum - OFFSET) 
                + 'a'
            );
        }

        return hash;
    }
};
