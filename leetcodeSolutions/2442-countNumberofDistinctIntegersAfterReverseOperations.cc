class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        auto rev = [](int n){
            int res = 0;
            while(n) {
                res = res * 10 + n % 10;
                n /= 10;
            }
            return res;
        };

        unordered_set<int> se;
        for(auto &num : nums) {
            se.insert(num);
            se.insert(rev(num));
        }

        return se.size();
    }
};
