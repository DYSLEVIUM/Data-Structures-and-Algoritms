#pragma GCC optimize("O3", "unroll-loops")

// class Solution {
// public:
//     vector<int> findAllPeople(const int & n, vector<vector<int>> & meetings, const int & firstPerson) {
//         cin.tie(nullptr)->sync_with_stdio(false);

//         using PII = pair<int, int>;

//         vector<vector<PII>> gr(n);
//         for(const auto & meeting : meetings) {
//             gr[meeting[0]].push_back({meeting[1], meeting[2]});
//             gr[meeting[1]].push_back({meeting[0], meeting[2]});
//         }

//         unordered_set<int> snitches;

//         priority_queue<PII, vector<PII>, greater<PII>> min_heap; // time, person
//         min_heap.push({0, 0}), min_heap.push({0, firstPerson});
//         while(!min_heap.empty()) {
//             const auto [min_time, person] = min_heap.top();
//             min_heap.pop();

//             if(snitches.count(person)) {
//                 continue;
//             }

//             snitches.insert(person);
//             for(const auto & [other, time]: gr[person]) {
//                 if(!snitches.count(other) && time >= min_time) {
//                     min_heap.push({time, other});
//                 }
//             }
//         }

//         return vector<int>(snitches.begin(), snitches.end());
//     }
// };

class Solution {
    class DSU {
        vector<int> rank;
        vector<int> parent;

    public:
        DSU(const size_t & n) {
            this->rank.resize(n);
            fill(this->rank.begin(), this->rank.end(), 0);
    
            this->parent.resize(n);
            iota(this->parent.begin(), this->parent.end(), 0);
        }

        int find(const int & node) {
            //  path compression
            return this->parent[node] = this->parent[node] == node ? node : this->find(this->parent[node]);
        }
    
        void merge(int node_1, int node_2) {
            node_1 = this->find(node_1);
            node_2 = this->find(node_2);
    
            //  both the nodes are present in the same set
            if (node_1 == node_2) return;
    
            //  either of the node can be the parent, so rank will increase
            if (this->rank[node_1] == this->rank[node_2]) ++this->rank[node_1];
    
            //  higher rank will be the parent (union by rank to reduce complexity)
            this->rank[node_1] < this->rank[node_2] ? this->parent[node_1] = node_2 : this->parent[node_2] = node_1;
        }

        void reset(const int & node) {
            this->parent[node] = node;
            this->rank[node] = 0;
        }
    };

    public:
    vector<int> findAllPeople(const int & n, vector<vector<int>> & meetings, const int & firstPerson) {
        cin.tie(nullptr)->sync_with_stdio(false);

        sort(meetings.begin(), meetings.end(), [](const auto & lhs, const auto & rhs){
            return lhs[2] < rhs[2];
        });

        DSU dsu(n);
        dsu.merge(0, firstPerson);

        int sz = meetings.size();
        for(int i = 0; i < sz; ++i) {
            int person1 = meetings[i][0], person2 = meetings[i][1], time = meetings[i][2];
            dsu.merge(person1, person2);

            if(i == sz - 1 || time != meetings[i + 1][2]) { // last meeting element of the block
                int j = i;
                while(j >= 0 && time == meetings[j][2]) {
                    int other1 = meetings[j][0], other2 = meetings[j][1];
                    if(dsu.find(other1) != dsu.find(0)) {// this person did not get to meet the snitch
                        dsu.reset(other1);                       
                    }
                    if(dsu.find(other2) != dsu.find(0)) {
                        dsu.reset(other2);                       
                    }

                    --j;
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            if(dsu.find(i) == dsu.find(0)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
