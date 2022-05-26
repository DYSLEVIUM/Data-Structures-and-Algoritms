class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, 
                                                    const vector<int> &b){
            if(a[0] == b[0]) return a[1] > b[1];    //  we greedily pick the biggest, so that if that envelope can be taken it is picked up, if the first is same, and later we optimize it (consider the case [[2,100],[3,200],[4,300],[5,500],[5,400],[5,250],[6,370],[6,360],[7,380]])
            return a[0] < b[0];
        });
        
        int n = envelopes.size();
        
        //  longest increasing subsequence
        vector<int> lis;
        for(auto &envelope: envelopes) {
            auto it = lower_bound(lis.begin(), lis.end(), envelope[1]);
            if(it == lis.end()) lis.push_back(envelope[1]);
            else *it = envelope[1];
        }
        
        return lis.size();
    }
};
