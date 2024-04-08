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
            if(!req[sandwich]) { // if there are no one, to take that sandwich, other remaining won't get it, as we can't get past this
                return req[!sandwich];
            }
            --req[sandwich];
        }

        return 0;
    }
};
