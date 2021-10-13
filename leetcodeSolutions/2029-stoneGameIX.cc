class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 =  0;
        int cnt1 =  0;
        int cnt2 =  0;

        for(int i=0;i<stones.size();++i) {
            cnt0+=(stones[i]%3==0);
            cnt1+=(stones[i]%3==1);
            cnt2+=(stones[i]%3==2);
        }
        
        if(!min(cnt1, cnt2)) return max(cnt1, cnt2) > 2 && cnt0&1;
        
        return abs(cnt1 - cnt2) > 2 || cnt0%2==0;
    }
};
