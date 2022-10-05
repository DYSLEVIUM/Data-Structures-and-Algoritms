class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<tuple<int, string, int>>> mp;
        unordered_set<int> se;
        for(int i = 0; i < transactions.size(); ++i) {
            stringstream sstr(transactions[i]);
            
            string substr;
            vector<string> transaction_state(4);
            int iter = 0;
            while(getline(sstr, substr, ',')) {
                transaction_state[iter++] = substr;
            }
            
            string name = transaction_state[0];
            int time = stoi(transaction_state[1]);
            int amount = stoi(transaction_state[2]);
            string city = transaction_state[3];

            // invalid amount
            if(amount > 1000) {
                se.insert(i);
            }

            // checking with other cities
            auto &con = mp[name];
            for(int j = 0; j < con.size(); ++j) {
                if(abs(get<0>(con[j]) - time) <= 60 && get<1>(con[j]) != city) {
                    se.insert(i);
                    se.insert(get<2>(con[j]));
                }
            }

            mp[name].push_back(make_tuple(time, city, i));
        }

        vector<string> ans;
        for(auto &x : se) {
            ans.push_back(transactions[x]);
        }

        return ans;
    }
};
