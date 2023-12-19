// class Solution {
// public:
//     vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
//         cin.tie(nullptr)->sync_with_stdio(false);

//         int rows = img.size(), cols = img[0].size();

//         auto get_avg = [&](const int & row, const int & col){
//             int total = 0, n = 0;
//             for(int curr_row = row - 1; curr_row <= row + 1; ++curr_row) {
//                 for(int curr_col = col - 1; curr_col <= col + 1; ++curr_col) {
//                     if(curr_row < 0 || curr_row >= rows || curr_col < 0 || curr_col >= cols) continue;
//                     total += img[curr_row][curr_col], ++n;
//                 }
//             }
//             return total / n;
//         };

//         vector<vector<int>> ans(rows, vector<int>(cols));
//         for(int row = 0; row < rows; ++row) {
//             for(int col = 0; col < cols; ++col) {
//                 ans[row][col] = get_avg(row, col);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        cin.tie(nullptr)->sync_with_stdio(false);

        constinit static const int MAXX = 256;
        constinit static const int offset = 8; // max value in image is log2(256) = 8

        int rows = img.size(), cols = img[0].size();

        auto get_avg = [&](const int & row, const int & col){
            int total = 0, n = 0;
            for(int curr_row = row - 1; curr_row <= row + 1; ++curr_row) {
                for(int curr_col = col - 1; curr_col <= col + 1; ++curr_col) {
                    if(curr_row < 0 || curr_row >= rows || curr_col < 0 || curr_col >= cols) continue;
                    total += img[curr_row][curr_col] & (MAXX - 1); // we get just the last 8 bits
                    ++n;
                }
            }
            return total / n;
        };

        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                img[row][col] |= get_avg(row, col) << offset; // enconding the smooth value
            }
        }

        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                img[row][col] >>= 8;
            }
        }

        return img;
    }
};
