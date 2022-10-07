class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 1-based indexing with 1 extra
        vector<int> flights(n + 2); // difference array

        for(auto &booking : bookings) {
            int start = booking[0], last = booking[1], seats = booking[2];
            flights[start] += seats;
            flights[last + 1] -= seats; // reason for 1 extra
        }

        for(int i = 1; i < n + 1; ++i) {
            flights[i] += flights[i - 1];
        }

        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            ans[i] = flights[i + 1];
        }

        return ans;
    }
};
