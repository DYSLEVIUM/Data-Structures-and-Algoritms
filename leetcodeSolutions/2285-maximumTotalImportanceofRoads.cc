class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        using ll = long long;
        
        vector<ll> city_roads(n);
        for(auto &road: roads) {
            ++city_roads[road[0]];
            ++city_roads[road[1]];
        }
        sort(city_roads.begin(), city_roads.end());
        
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += city_roads[i] * (i + 1LL);
        }

        return ans;
    }
};
