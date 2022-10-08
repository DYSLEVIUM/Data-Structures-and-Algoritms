class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        multiset<int> se;
        for(auto &num : nums) {
            se.insert(num * num);
        }

        return vector<int>(se.begin(), se.end());
    }
};
