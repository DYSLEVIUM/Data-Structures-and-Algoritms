class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = plants.size();

        int ans = 0;

        int i = 0, j = n - 1;
        int waterA = capacityA, waterB = capacityB;
        while(i <= j) {
            if(i == j) {
                int * maxx = nullptr;
                if(waterA >= waterB) {
                    maxx = &waterA;
                } else {
                    maxx = &waterB;
                }

                ans += *maxx < plants[i++];
                break;
            }

            ans += waterA < plants[i];
            ans += waterB < plants[j];

            waterA = waterA < plants[i] ? capacityA : waterA;
            waterA -= plants[i++];

            waterB = waterB < plants[j] ? capacityB : waterB;
            waterB -= plants[j--];
        }

        return ans;
    }
};
