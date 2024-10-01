#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    bool canArrange(vector<int> arr, const int & k) {
        unordered_map<int, int> mp;
        for(auto & num : arr) {
            ++mp[(num % k + k) % k];
        }

        for(auto & num : arr) {
            int rem = (num % k + k) % k;

            if(!rem) {
                if(mp[rem] & 1) {
                    return false;
                }
            } else if(mp[rem] != mp[k - rem]) {
                return false;
            }
        }

        return true;
    }
};
