class Solution {
public:
    int numSplits(string s) {
//         unordered_map<char,int> mpl, mpr;
        
//         for(auto ch:s) ++mpr[ch];

//         int ans = 0;
        
//         int l = 0;  //  left string has no distinct intially
//         int r = mpr.size(); //  right string has all the distinct initially;
        
//         for(auto ch:s){
//             --mpr[ch];  //  removing from the right
            
//             if(mpl[ch]==0) ++l;
            
//             if(mpr[ch]==0) --r;
            
//             ans += l==r;
            
//             ++mpl[ch];  //  adding to the left
//         }
        
//         return ans;
        
        //  using prefix array
        unordered_set<char> se;
        
        vector<int> pre(s.size()), suff(s.size());
        
        for(int i=0;i<s.size();++i) {
            se.insert(s[i]);
            pre[i] = se.size();
        }
        
        se.clear();
        
        for(int i=s.size()-1;i>=0;--i) {
            se.insert(s[i]);
            suff[i] = se.size();
        }
        
        int ans = 0;
        
        for(int i=1;i<s.size();++i) ans += pre[i-1]==suff[i];
        
        return ans;
    }
};
