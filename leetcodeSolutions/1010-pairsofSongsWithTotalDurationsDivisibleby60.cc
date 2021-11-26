class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        vector<int> fa(60);

        for(int i=0;i<time.size();++i) fa[time[i]%60]++;
        
        int ans = 0;
        
        for(int i=1;i<30;++i) ans+=(fa[i]*fa[60-i]);
        
        //  dividing by 2! as the objects are same
        ans+=(fa[30]*fa[30]-fa[30])/2;  //  30 will combine with itself
        ans+=(fa[0]*fa[0]-fa[0])/2; //  60 will combine with itself

        return ans;
    }
};
