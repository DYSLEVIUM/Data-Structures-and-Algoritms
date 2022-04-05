class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        auto is_valid_citation = [&citations, &n](const int& x){
            int te = lower_bound(citations.begin(), citations.end(), x) - citations.begin();
            return n - te >= x;
        };
        
        int lo = 0, hi = n;
        while(lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            
            if(is_valid_citation(mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        
        return hi;
    }
};
