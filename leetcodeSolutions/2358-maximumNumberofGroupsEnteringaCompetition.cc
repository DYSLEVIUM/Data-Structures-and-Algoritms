class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        
        // binary search on answer O(nlog n)
//         sort(grades.rbegin(), grades.rend());
        
//         auto check = [&](int x){
//             int temp = x;
//             vector<pair<int, int>> grps(x);
            
//             while(iter < n && x) {
//                 for(int i = 0; i < x; ++i) {
//                     if(iter == n) {
//                         break;
//                     }
//                     grps[i].first += grades[iter++];
//                     ++grps[i].second;
//                 }
                
//                 for(int i = 1; i < x; ++i) {
//                     while(grps[i].first != grps[i - 1].first && grps[i].second != grps[i - 1].second) {
//                         if(iter == n) {
//                             return false;
//                         }
//                         grps[i - 1].first += grades[iter++];
//                         ++grps[i - 1].second;
//                     }
//                 }

//                 --x;
//             }
            
//             for(int i = 1; i < temp; ++i) {
//                 if(grps[i].first == grps[i - 1].first || grps[i].second == grps[i - 1].second) {
//                     return false;
//                 }
//             }
            
//             return true;
//         };

//         int lo = 1, hi = n;
//         int ans = 1;
//         while(lo < hi) {
//             int mid = lo + ((hi - lo) >> 1);
            
//             if(check(mid)) {
//                 ans = mid;
//                 lo = mid + 1;    
//             } else {
//                 hi = mid;
//             }
//         }
        
//         return ans;
        
        // O(log n)
        return (-1 + sqrt(1 + 8 * n)) / 2;
    }
};
