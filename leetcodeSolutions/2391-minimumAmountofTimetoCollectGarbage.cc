// class Solution {
// public:
//     int garbageCollection(vector<string>& garbage, vector<int>& travel) {
//         cin.tie(nullptr)->sync_with_stdio(false);

//         int n = garbage.size();

//         vector<unordered_map<char, int>> suff(n);
//         for(int i = n - 1; i >= 0; --i) {
//             for(const char & type: garbage[i]) {
//                 ++suff[i][type];
//             }

//             for(const char & type: "MPG") {
//                 suff[i][type] += i + 1 >= n ? 0 : suff[i + 1][type];
//             }
//         }

//         int ans = 0;
//         for(int i = 0; i < n; ++i) {
//             int total_trucks = (!!suff[i]['M']) + (!!suff[i]['P']) + (!!suff[i]['G']); // if we don't need the trucks to travel, we won't
//             ans += total_trucks * (i - 1 >= 0 ? travel[i - 1] : 0) + garbage[i].size();
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int garbageCollection(vector<string>& garbage, vector<int>& travel) {
//         cin.tie(nullptr)->sync_with_stdio(false);

//         int n = garbage.size();

//         for(int i = 1; i < travel.size(); ++i) {
//             travel[i] += travel[i - 1];
//         }

//         // space is O(1)
//         unordered_map<char, pair<int, int>> mp; // type -> time and cnt;

//         for(int i = 0; i < n; ++i) {
//             for(const char & type: garbage[i]) {
//                 mp[type].first = i - 1 < 0 ? 0 : travel[i - 1];
//                 mp[type].second += 1;
//             }
//         }

//         int ans = 0;
//         for(const auto & [_, time_cnt]: mp) {
//             ans += time_cnt.first + time_cnt.second;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = garbage.size();

        for(int i = 1; i < travel.size(); ++i) {
            travel[i] += travel[i - 1];
        }

        int ans = 0;

        unordered_map<char, int> last_pos;
        for(int i = 0; i < n; ++i) {
            for(const char & type : garbage[i]) {
                last_pos[type] = i;
            }
            ans += garbage[i].size();
        }

        for(const char & type : "MPG") {
            ans += last_pos[type] == 0 ? 0 : travel[last_pos[type] - 1];
        }

        return ans;
    }
};
