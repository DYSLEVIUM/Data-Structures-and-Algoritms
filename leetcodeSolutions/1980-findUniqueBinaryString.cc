// class Solution {
// public:
//     string findDifferentBinaryString(vector<string>& nums) {
//         int n = nums.size();

//         unordered_set<string> se;
//         for(const string & s: nums) {
//             se.insert(s);
//         }

//         string ans;
//         auto generate_bin = [&](const auto & generate_bin, const int & x, const string & curr){
//             if(!x) {
//                 if(!se.count(curr)) {
//                     ans = curr;
//                 }
//                 return;
//             }

//             generate_bin(generate_bin, x - 1, "0" + curr);
//             generate_bin(generate_bin, x - 1, "1" + curr);
//         };

//         generate_bin(generate_bin, n, "");
//         return ans;
//     }
// };

// cantor's diagonal argument
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for(int i = 0; i < nums.size(); ++i) {
            char curr = nums[i][i];
            ans += curr == '0' ? '1' : '0';
        }
        return ans;
    }
};
