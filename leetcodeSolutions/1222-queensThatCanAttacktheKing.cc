class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<vector<int>> se;
        for(auto &queen: queens) {
            se.insert(queen);
        }

        vector<vector<int>> attacker;
        auto is_attacked = [&](){
            int r, c;

            // row-down
            r = king[0], c = king[1];
            while(c < 8) {
                if(se.count({r, c})) {
                    attacker.push_back({r, c});
                    break;
                }
                ++c;
            }

            // row-up
            r = king[0], c = king[1];
            while(c >= 0) {
                if(se.count({r, c})) {
                    attacker.push_back({r, c});
                    break;
                }
                --c;
            }

            // col-right
            r = king[0], c = king[1];
            while(r < 8) {
                if(se.count({r, c})) {
                    attacker.push_back({r, c});
                    break;
                }
                ++r;
            }

            // col-left
            r = king[0], c = king[1];
            while(r >= 0) {
                if(se.count({r, c})) {
                    attacker.push_back({r, c});
                    break;
                }
                --r;
            }

            // left diagonal-up check
            r = king[0], c = king[1];
            while(r >= 0 && c >= 0) {
                if(se.count({r, c})) {
                    attacker.push_back({r, c});
                    break;
                }
                --r, --c;
            }

            // left diagonal-down check
            r = king[0], c = king[1];
            while(r < 8 && c < 8) {
                if(se.count({r, c})) {
                    attacker.push_back({r, c});
                    break;
                }

                ++r, ++c;
            }

            // right diagonal-up check
            r = king[0], c = king[1];
            while(r >= 0 && c < 8) {
                if(se.count({r, c})) {
                    attacker.push_back({r, c});
                    break;
                }
                --r, ++c;
            }

            // right diagonal-down check
            r = king[0], c = king[1];
            while(r < 8 && c >= 0) {
                if(se.count({r, c})) {
                    attacker.push_back({r, c});
                    break;
                }
                ++r, --c;
            }

            return false;
        };
        is_attacked();

        return attacker;
    }
};
