class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size(), minn = INT_MAX;
        for(int i = 0; i < 2; ++i) {
            int j = start, sum = 0;
            while(j != destination) {
                sum += distance[j];
                j = (j + 1) % n;
            }
            minn = min(minn, sum);
            swap(start, destination);
        }

        return minn;
    }
};
