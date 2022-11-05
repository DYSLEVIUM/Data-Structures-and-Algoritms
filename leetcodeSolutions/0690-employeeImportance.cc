/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();

        unordered_map<int, int> id_idx;
        for(int i = 0; i < n; ++i) id_idx[employees[i]->id] = i;

        auto dfs = [&](const auto & dfs, const int & curr_id) -> int {
            Employee * employee = employees[id_idx[curr_id]];
            int total = employee->importance;
            for(auto & subordinate : employee->subordinates) 
                total += dfs(dfs, subordinate);
            return total;
        };
        
        return dfs(dfs, id);
    }
};
