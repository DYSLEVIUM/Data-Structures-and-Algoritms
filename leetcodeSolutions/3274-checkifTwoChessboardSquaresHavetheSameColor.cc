#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    bool checkTwoChessboards(const string & coordinate1, const string & coordinate2) {
        const auto normalize = [](const string & coord){
            return (coord[0] - 'a') + (coord[1] - '1');
        };

        return (normalize(coordinate1) & 1) == (normalize(coordinate2) & 1);
    }
};
