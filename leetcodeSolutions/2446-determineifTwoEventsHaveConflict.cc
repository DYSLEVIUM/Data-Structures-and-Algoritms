class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        auto convert = [](const string & s){
            int hrs = s[0] * 10 + s[1];
            int mins = s[3] * 10 + s[4];
            
            return hrs * 60 + mins;
        };
        
        int s1 = convert(event1[0]), s2 = convert(event2[0]);
        int e1 = convert(event1[1]), e2 = convert(event2[1]);
        
        if(s1 > s2) swap(s1, s2), swap(e1, e2);
        
        return e1 >= s2;
    }
};
