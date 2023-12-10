// class Solution {
// public:
//     int findRadius(vector<int>& houses, vector<int>& heaters) {
//         cin.tie(nullptr)->sync_with_stdio(false);

//         constinit static const int INF = INT_MAX;

//         int ho_sz = houses.size(), he_sz = heaters.size();

//         sort(houses.begin(), houses.end());
//         sort(heaters.begin(), heaters.end());

//         auto check = [&](const int & radius){
//             int i = 0, j = 0;
//             while(i < ho_sz && j < he_sz) {
//                 if(houses[i] < heaters[j] - radius) {
//                     return false;
//                 } else if(houses[i] > heaters[j] + radius) {
//                     ++j;
//                 } else {
//                     ++i;
//                 }
//             }
//             return i == ho_sz;
//         };

//         int lo = 0, hi = INF;
//         while(lo < hi) {
//             int mid = lo + ((hi - lo) >> 1);

//             if(check(mid)) {
//                 hi = mid;
//             } else {
//                 lo = mid + 1;
//             }
//         }
//         return lo;
//     }
// };

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        cin.tie(nullptr)->sync_with_stdio(false);

        constinit static const int INF = INT_MAX;

        int ho_sz = houses.size(), he_sz = heaters.size();

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        // dist to rhs heater
        vector<int> res(ho_sz, INF);
        for(int i = 0, j = 0; i < ho_sz && j < he_sz; ) {
            if(houses[i] <= heaters[j]) {
                res[i] = heaters[j] - houses[i];
                ++i;
            } else {
                ++j;
            }
        }

        // dist to lhs heater
        for(int i = ho_sz - 1, j = he_sz - 1; i >= 0 && j >= 0; ) {
            if(houses[i] >= heaters[j]) {
                int lhs = houses[i] - heaters[j];
                res[i] = min(res[i], lhs);
                --i;
            } else {
                --j;
            }
        }

        return *max_element(res.begin(), res.end());
    }
};
