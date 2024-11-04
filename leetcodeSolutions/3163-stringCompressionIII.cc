#pragma GCC optmize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    string compressedString(string & word) {
        const int n = word.size();

        int i = 0;
        string comp = "";
        while(i < n) {
            int cnt = 0;
            while(
                i + cnt < n &&
                cnt < 9 &&
                word[i] == word[i + cnt]
            ) {
                ++cnt;
            }

            comp += to_string(cnt) + word[i];
            i = i + cnt;
        }

        return comp;
    }
};
