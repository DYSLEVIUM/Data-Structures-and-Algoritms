// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
//         cin.tie(nullptr)->sync_with_stdio(false);

//         int sz = 0;
//         unordered_map<int, vector<int>> groups;
//         for(int i = nums.size() - 1; i >= 0; --i) {
//             for(int j = 0; j < nums[i].size(); ++j) {
//                 groups[i + j].push_back(nums[i][j]);
//                 ++sz;
//             }
//         }

//         vector<int> ans;
//         ans.reserve(sz);

//         int group = 0;
//         while(groups.count(group)) {
//             for(const int & num : groups[group++]) {
//                 ans.push_back(num);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        cin.tie(nullptr)->sync_with_stdio(false);

        vector<int> ans;

        queue<pair<int, int>> qu;
        qu.push({0, 0});
        
        while(!qu.empty()) {
            auto &[row, col] = qu.front();
            ans.push_back(nums[row][col]);

            if(col == 0 && row + 1 < nums.size()) {
                qu.push({row + 1, 0});
            }

            if(col + 1 < nums[row].size()) {
                qu.push({row, col + 1});
            }

            qu.pop();
        }

        return ans;
    }
};
