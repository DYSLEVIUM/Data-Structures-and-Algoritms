class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<tuple<int, string, int>>> mp;
        unordered_set<int> se;

        vector<string> ans;
        for(int i = 0; i < transactions.size(); ++i) {
            auto transaction = transactions[i];

            stringstream sstr(transaction);
            
            string substr;
            vector<string> transaction_state;
            while(getline(sstr, substr, ',')) {
                transaction_state.push_back(substr);
            }
            
            string name = transaction_state[0];
            int time = stoi(transaction_state[1]);
            int amount = stoi(transaction_state[2]);
            string city = transaction_state[3];

            if(amount > 1000) {
                se.insert(i);
            }

            mp[name].push_back(make_tuple(time, city, i));
        }

        for(auto &[_, con] : mp) {
            sort(con.begin(), con.end());

            int n = con.size();

            for(int i = 0; i < n; ++i) {
                // cout << get<0>(con[i]) << ' ' << get<1>(con[i]) << ' ' << get<2>(con[i]) << '\n';
                for(int j = i + 1; j < n; ++j) {
                    if(get<0>(con[j]) - get<0>(con[i]) <= 60 && get<1>(con[j]) != get<1>(con[i])) {
                        se.insert(get<2>(con[i]));
                        se.insert(get<2>(con[j]));
                    }
                }
            }

        }
        
        for(auto &x : se) {
            ans.push_back(transactions[x]);
        }

        return ans;
    }
};
