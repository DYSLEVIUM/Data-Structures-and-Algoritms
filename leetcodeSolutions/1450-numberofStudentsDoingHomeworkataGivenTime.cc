class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += startTime[i] <= queryTime && queryTime <= endTime[i];  
        }

        return ans;
    }
};

class Solution1 {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        constexpr int total_time = 1002;
        static_assert(total_time == 1002);

        int study[total_time] = {};
        for(auto &t : startTime) {
            ++study[t];
        }
        
        for(auto &t : endTime) {
            --study[t + 1];
        }

        // sweep line algorithm
        for(int i = 1; i < total_time; ++i) {
            study[i] += study[i - 1];
        }

        return study[queryTime];
    }
};
