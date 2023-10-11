class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // line sweep algorithm
        map<int, int> difference;
        difference[0] = 0;
        
        for(const vector<int>& flower : flowers) {
            ++difference[flower[0]];
            --difference[flower[1] + 1];
        }

        int n = difference.size();

        // do the line sweep
        vector<int> positions; // we need this array to find the position till where to do the prefix for the person array
        positions.reserve(n);

        int sum = 0;
        vector<int> prefix;
        prefix.reserve(n);
        for(auto &[time, cnt] : difference) {
            sum += cnt;
            prefix.push_back(sum);
            positions.push_back(time);
        }

        vector<int> ans;
        ans.reserve(people.size());
        for(const int& person : people) {
            int pos = upper_bound(positions.begin(), positions.end(), person) - positions.begin() - 1;
            ans.push_back(prefix[pos]);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // binary search
        vector<int> starts;
        vector<int> ends;

        for(const vector<int>& flower : flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1] + 1);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> ans;
        ans.reserve(people.size());
        for(const int& person : people) {
            int i = upper_bound(starts.begin(), starts.end(), person) - starts.begin(); // how many flowers have started blooming
            int j = upper_bound(ends.begin(), ends.end(), person) - ends.begin(); // how many flowers have stopped blooming

            ans.push_back(i - j);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // this idea is similar to event streaming
        int n_people = people.size();
        vector<int> ans(n_people);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for(const vector<int>& flower: flowers) {
            min_heap.push({ flower[0], 1 });
            min_heap.push({ flower[1] + 1, -1 });
        }

        for(int i = 2; const int& person: people) { // starting from 2, to differentiate between flower and person
            min_heap.push({ person, i++});
        }

        int cnt = 0;
        while(!min_heap.empty()) {
            auto &[_, val] = min_heap.top();
            
            if(val >= 2) { // person
                ans[val - 2] = cnt;
            } else { // flower
                cnt += val;
            }

            min_heap.pop();
        }

        return ans;
    }
};
