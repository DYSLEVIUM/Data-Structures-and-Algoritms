class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        //  making a complete graph
        vector<vector<pair<int, int>>> gr(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                gr[i].push_back({j, dist});
                gr[j].push_back({i, dist});
            }
        }

        vector<bool> mst(n, false);
        vector<int> key(n, INT_MAX);
        key[0] = 0;

        for(int i = 0; i < n; ++i) {
            int minn = INT_MAX, minn_idx;
            for(int j = 0; j < n; ++j) {
                if(!mst[j] && minn > key[j]) {
                    minn = key[j];
                    minn_idx = j;
                }
            }
            
            mst[minn_idx] = true;
            for(auto &neighbour: gr[minn_idx]) {
                auto node = neighbour.first, weight = neighbour.second;
                if(!mst[node] && key[node] > weight) {
                    key[node] = weight;
                }
            }
        }

        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += key[i];
        }
                                                     
        return sum;
    }
};
