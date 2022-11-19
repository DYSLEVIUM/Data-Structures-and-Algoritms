class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() == 1) return trees;
        
        auto cmp = [](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        };

        sort(trees.begin(), trees.end(), cmp);

        auto get_area = [](const vector<int> & ref, const vector<int> & p, const vector<int> & q){
            vector<int> p_te{p[0] - ref[0], p[1] - ref[1]}, q_te{q[0] - ref[0], q[1] - ref[1]};
            return p_te[1] * q_te[0] - p_te[0] * q_te[1];
        };

        vector<vector<int>> convex;
        for(int i = 0; i < 2; ++i) {
            int sz = convex.size(); // this is to handle the two cases independently
            for(vector<int> & tree : trees) {
                while(convex.size() - sz >= 2) {
                    vector<int> slast = convex.end()[-2];
                    vector<int> last = convex.end()[-1];

                    if(get_area(slast, last, tree) <= 0) break;

                    convex.pop_back();
                }
                convex.push_back(tree);
            }

            reverse(trees.begin(), trees.end());
            convex.pop_back();
        }

        sort(convex.begin(), convex.end(), cmp);
        convex.erase(unique(convex.begin(), convex.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] == b[0] && a[1] == b[1];
        }), convex.end());

        return convex;
    }
};
