// class Solution {
// public:
//     int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//         sort(arr.begin(), arr.end());
//         arr[0] = 1;

//         for(int i = 1; i < arr.size(); ++i) {
//             if(arr[i] - arr[i - 1] <= 1) {
//                 continue;
//             }

//             arr[i] = arr[i - 1] + 1;
//         }

//         return arr.back();
//     }
// };

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnts(n + 1);

        for(const int & num : arr) {
            ++cnts[min(num, n)];
        }

        int ans = 1;
        for(int num = 2; num <= n; ++num) {
            ans = min(ans + cnts[num], num); // we cannot exceed num;
        }

        return ans;
    }
};
