#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    bool canMakeSubsequence(const string & str1, const string & str2) {
        int n1 = str1.size(), n2 = str2.size();
        
        int i, j;
        i = j = 0;
        while(i < n1 && j < n2) {
            if(str1[i] == str2[j] ||
                ((str1[i] + 1 - 'a') % 26) + 'a' == str2[j]
            ) {
                ++j;
            }
            ++i;
        }

        if(j == n2) {
            return true;
        }

        return false;
    }
};
