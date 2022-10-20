class Solution {
public:
    vector<vector<string>> displayTable(const vector<vector<string>> & orders) {
        unordered_map<string_view, unordered_map<string_view, int>> mp;
        
        auto cmp = [](const string_view & lhs, const string_view & rhs){
            if(lhs.size() == rhs.size()) return lhs < rhs;
            return lhs.size() < rhs.size();
        };
        
        set<string_view, decltype(cmp)> tables(cmp);
        set<string_view> foods;
        for(auto &order : orders) {
            string_view table = order[1], food = order[2];
            ++mp[table][food];
            tables.insert(table), foods.insert(food); 
        }
        
        int rows = tables.size() + 1, cols = foods.size() + 1;
        
        vector<vector<string>> ans(rows, vector<string>(cols));
        ans[0][0] = "Table";
        
        auto f_it = foods.begin();
        for(int col = 1; col < cols; ++col) ans[0][col] = *f_it, ++f_it;
        
        auto t_it = tables.begin();
        for(int row = 1; row < rows; ++row) ans[row][0] = *t_it, ++t_it;

        for(int row = 1; row < rows; ++row) {
            for(int col = 1; col < cols; ++col) {
                string_view table = ans[row][0], food = ans[0][col];
                ans[row][col] = to_string(mp[table][food]);
            }
        }
        
        return ans;
    }
};
