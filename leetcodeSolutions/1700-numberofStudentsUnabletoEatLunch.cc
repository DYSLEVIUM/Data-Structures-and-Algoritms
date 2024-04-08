#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        const int n = students.size();

        int req[2]{};
        for(const int & student: students) {
            ++req[student];
        }

        for(const int & sandwich: sandwiches) {
            if(sandwich && !req[1]) {
                return req[0];
            }

            if(!sandwich && !req[0]) {
                return req[1];
            }

            --req[sandwich];
        }

        return 0;
    }
};
