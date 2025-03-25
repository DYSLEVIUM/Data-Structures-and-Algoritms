#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    bool checkValidCuts(const int & n, vector<vector<int>> & rectangles) {
        const int sz = rectangles.size();
        auto check_in_principal_axis = [&](const auto & axis){
            int lines = 0;
            sort(rectangles.begin(), rectangles.end(), [&](const auto & lhs, const auto & rhs){
                return lhs[axis] < rhs[axis];
            });

            auto further_end = rectangles[0][axis + 2];
            for(int i = 1; i < sz; ++i) {
                const auto & curr_rect = rectangles[i];
                lines += further_end <= curr_rect[axis];

                further_end = max(further_end, curr_rect[axis + 2]);
            }

            return lines > 1;
        };

        return check_in_principal_axis(0) || check_in_principal_axis(1);
    }
};
