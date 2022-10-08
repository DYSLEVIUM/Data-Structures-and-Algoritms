class Solution {
public:
    string reformatDate(string date) {
        stringstream ss(date);
        string w;
        vector<string> splits;
        while(ss >> w) {
            splits.push_back(w);
        }

        string ans = splits[2];
        ans += '-';

        unordered_map<string, string> month{{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        ans += month[splits[1]];
        ans += '-';
  
        if(splits[0][1] >= '0' && splits[0][1] <= '9') {
            ans += splits[0][0];
            ans += splits[0][1];
        } else {
            ans += '0';
            ans += splits[0][0];
        }

        return ans;
    }
};
