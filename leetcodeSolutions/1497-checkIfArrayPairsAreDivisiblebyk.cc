#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    bool canArrange(const vector<int> & arr, const int & k) {
        vector<int> freq(k, 0);
        for(auto & num : arr) {
            ++freq[(num % k + k) % k];
        }

        if(freq[0] & 1) {
            return false;
        }

        for(int i = 1; i < k; ++i) {
            if(freq[i] != freq[k - i]) {
                return false;
            }
        }

        return true;
    }
};
