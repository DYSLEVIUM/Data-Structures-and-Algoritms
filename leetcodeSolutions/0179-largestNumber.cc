class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &n1, const int &n2){
            string s1 = to_string(n1), s2 = to_string(n2);
            return s1 + s2 > s2 + s1;
        });
        
        string ans = "";
        for(auto &num : nums) {
            ans += to_string(num);
        }
        
        reverse(ans.begin(), ans.end());
        while(ans.length() > 1 && ans.back() == '0') {
            ans.pop_back();
        }
        
        return string(ans.rbegin(), ans.rend());
    }
};
