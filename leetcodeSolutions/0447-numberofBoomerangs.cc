#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>> & points) {
        auto dist = [](vector<int> & p1, vector<int> & p2){
            int xp = p2[0] - p1[0];
            int yp = p2[1] - p1[1];

            return xp * xp + yp * yp;
        };

        int num_boomerangs = 0;
        unordered_map<int, int> distances;
        for(auto & p1: points) {
            for(auto & p2: points) {
                ++distances[dist(p1, p2)];
            }

            // np2
            for(auto &[_, cnt]: distances) {
                num_boomerangs += cnt * (cnt - 1);
            }
 
            distances.clear();
        }

        return num_boomerangs;
    }
};
