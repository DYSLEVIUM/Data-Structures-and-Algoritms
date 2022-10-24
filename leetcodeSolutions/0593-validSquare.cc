class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pair<int, int>> points;
        points.reserve(4);

        points.push_back({p1[0], p1[1]});
        points.push_back({p2[0], p2[1]});
        points.push_back({p3[0], p3[1]});
        points.push_back({p4[0], p4[1]});

        sort(points.begin(), points.end());

        auto get_dist = [](const pair<int, int> & p, const pair<int, int> & t){
            return pow(p.first - t.first, 2) + pow(p.second - t.second, 2);
        };

        auto check_ortho = [](const pair<int, int> & p1, const pair<int, int> & p2, 
                                    const pair<int, int> & p3){
            // m1 * m2 = -1 for orthogonallity
  
            int m1n = p1.second - p2.second;
            int m1d = p1.first - p2.first;

            int m2n = p1.second - p3.second;
            int m2d = p1.first - p3.first;

            return m1n * m2n == -m1d * m2d;
        };

        int dist = get_dist(points[0], points[1]);
        return dist &&
                dist == get_dist(points[0], points[2]) &&
                dist == get_dist(points[1], points[3]) &&
                dist == get_dist(points[2], points[3]) &&
                check_ortho(points[0], points[1], points[2]);
    }
};
