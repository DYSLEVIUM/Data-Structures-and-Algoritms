class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long curr_time = customers[0][0], sum = 0, cnt = 0;
        for(vector<int> & customer : customers) {
            long long arrival = customer[0], time = customer[1];
            
            // taking max for the case when the customer arrives when the chef is idle
            long long waiting = max(curr_time - arrival, 0LL);
            curr_time = max(curr_time, arrival) + time;

            sum += waiting + time;
        }

        return double(sum) / customers.size();
    }
};
