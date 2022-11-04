class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        for(int i = 0; i < 20; ++i) {
            for(int j = 0; pow(x, i) + pow(y, j) < INT_MAX && j < 20; ++j) {
                int curr = pow(x,i) + pow(y, j);
                if(curr <= bound) ans.insert(curr);
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
