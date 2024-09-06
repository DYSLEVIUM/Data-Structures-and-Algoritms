#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    string stringHash(const string & s, const int & k) {
        int n = s.size();

        const auto hash_fn = [](const int & sum){
            return sum % 26;
        };

        string hash;
        hash.reserve(n / k);

        const int offset = 'a' * k;
        
        for(int i = 0, sum = 0; const char & ch: s) {
            sum += ch;

            if(++i != k) {
                continue;
            }
            
            hash.push_back(
                hash_fn(sum - offset) 
                + 'a'
            );
            
            i = sum = 0;
        }

        return hash;
    }
};
