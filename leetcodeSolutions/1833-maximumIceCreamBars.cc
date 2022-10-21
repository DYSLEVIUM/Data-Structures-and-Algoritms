class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();

        int cnt = 0;
        sort(costs.begin(), costs.end());
        for(auto &cost : costs) {
            if(cost > coins) break;
            ++cnt, coins -= cost;
        }

        return cnt;
    }
};
