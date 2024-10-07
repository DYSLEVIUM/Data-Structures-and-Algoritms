#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int minLength(string & s) {
        static const unordered_set<string> discard{"AB", "CD"};

        const int n = s.size();
        
        string new_str = "#";
        for(int i = 0; i < n; ++i) {
            string check;
            check += new_str.back();
            check += s[i];
            if(discard.count(check)) {
                new_str.pop_back();
                continue;
            }

            new_str += s[i];
        }

        return new_str.size() - 1;
    }
};
