#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int lengthOfLastWord(const string & s) {
        stringstream ss(s);
        
        int ans = -0x3f3f3f;
        
        string word;
        while(ss >> word) {
            ans = word.size();
        }

        return ans;
    }
};
