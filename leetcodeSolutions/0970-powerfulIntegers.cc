class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        for(int i = 0; i < 19; ++i) {
            for(int j = 0; pow(x,i) + pow(y, j) < INT_MAX; ++j) {
                int curr = pow(x,i) + pow(y, j);
                if(curr <= bound) ans.insert(curr);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
