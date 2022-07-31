class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> se;
        for(auto &num : nums) {
            if(num) {
                se.insert(num);
            }
        }
        
        return se.size();
    }
};
