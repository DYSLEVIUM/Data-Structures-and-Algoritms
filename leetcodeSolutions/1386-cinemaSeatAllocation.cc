// class Solution {
// public:
//     int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
//         cin.tie(nullptr)->sync_with_stdio(false);

//         map<int, unordered_set<int>> mp;
//         for(const auto & reservedSeat: reservedSeats) {
//             int row = reservedSeat[0], col = reservedSeat[1];
//             mp[row].insert(col);
//         }

//         auto check_range = [&mp](const int & row, const int & st, const int & ed){
//             for(int i = st; i <= ed; ++i) {
//                 if(mp[row].count(i)) {
//                     return 0;
//                 }
//             }
//             return 1;
//         };

//         vector<pair<int, int>> valids2 = {{2, 5}, {6, 9}};
//         pair<int, int> valid_middle = {4, 7};

//         int ans = (n - mp.size()) << 1; // all other rows are totally unreserved, and greedily we can get 2 for every row
//         for(const auto & [row, _]: mp) {
//             int cnt = 0;
//             for(const auto & [st, ed]: valids2) {
//                 cnt += check_range(row, st, ed);
//             }

//             if(!cnt) { // the middle row is only valid when the first two are not choosen
//                 const auto & [st, ed] = valid_middle;
//                 cnt += check_range(row, st, ed);
//             }

//             ans += cnt;
//         };

//         return ans;
//     }
// };

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        cin.tie(nullptr)->sync_with_stdio(false);

        unordered_map<int, int> mp;
        for(const auto & reservedSeat: reservedSeats) {
            int row = reservedSeat[0], col = reservedSeat[1];
            mp[row] |= 1 << col;
        }

        int ans = (n - mp.size()) << 1;
        for(const auto & [row, mask]: mp) {
            if(!(mask & (1 << 2)) && !(mask & (1 << 3)) && !(mask & (1 << 4)) && !(mask & (1 << 5))) {
                ++ans;
                if(!(mask & (1 << 6)) && !(mask & (1 << 7)) && !(mask & (1 << 8)) && !(mask & (1 << 9))) {
                    ++ans;
                }
            } else if(!(mask & (1 << 4)) && !(mask & (1 << 5)) && !(mask & (1 << 6)) && !(mask & (1 << 7)) || 
                (!(mask & (1 << 6)) && !(mask & (1 << 7)) && !(mask & (1 << 8)) && !(mask & (1 << 9)))
            ) {
                ++ans;
            }
        }

        return ans;
    }
};
