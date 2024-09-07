#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int generateKey(const int & num1, const int & num2, const int & num3) {
        const auto pad = [](const int & num){
            string num_str = to_string(num);

            int digits = num_str.size();
            if(digits < 4) {
                num_str = string(4 - digits, '0') + num_str;
            }

            return num_str;
        };

        string pad1 = pad(num1), pad2 = pad(num2), pad3 = pad(num3);

        string ans;
        ans.reserve(4);

        for(int i = 0; i < 4; ++i) {
            ans[i] = min({pad1[i], pad2[i], pad3[i]});
        }

        return stoi(ans);
    }
};
