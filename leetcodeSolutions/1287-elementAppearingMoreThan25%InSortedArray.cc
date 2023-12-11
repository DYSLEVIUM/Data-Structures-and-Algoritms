// class Solution {
// public:
//     int findSpecialInteger(vector<int>& arr) {
//         cin.tie(nullptr)->sync_with_stdio(false);

//         int sz = arr.size();
//         int threshold = sz / 4;

//         int i = 1, cnt = 1;
//         while(i < sz && cnt <= threshold) {
//             cnt = arr[i - 1] == arr[i++] ? cnt + 1 : 1;
//         }

//         return arr[i - 1];
//     }
// };

// class Solution {
// public:
//     int findSpecialInteger(vector<int>& arr) {
//         cin.tie(nullptr)->sync_with_stdio(false);

//         int sz = arr.size();
//         int threshold = sz / 4;

//         for(int i = 0; i < sz - threshold; ++i) {
//             if(arr[i] == arr[i + threshold]) {
//                 return arr[i];
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int sz = arr.size();
        int threshold = sz / 4;

        // the candidate will have to appear at these boundary points
        for(const int & candidate : { arr[sz / 4], arr[sz / 2], arr[3 * sz / 4] }) {
            int le = lower_bound(arr.begin(), arr.end(), candidate) - arr.begin();
            int ri = upper_bound(arr.begin(), arr.end(), candidate) - arr.begin() - 1;

            if(ri - le + 1 > threshold) {
                return candidate;
            }
        }

        return -1;
    }
};
