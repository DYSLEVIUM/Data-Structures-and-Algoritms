#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    string largestNumber(vector<int> & nums) {
        int n = nums.size();

        vector<string> nums_str(n);
        for(int i = 0; i < n; ++i) {
            nums_str[i] = to_string(nums[i]);
        }

        sort(nums_str.begin(), nums_str.end(), [](auto & lhs, auto & rhs){
            string x = lhs + rhs;
            string y = rhs + lhs;
            
            return x > y;
        });

        if(nums_str[0] == "0") {
            return nums_str[0];
        }

        string ans;
        for(auto & num_str: nums_str) {
            ans += num_str;
        }

        return ans;
    }
};
