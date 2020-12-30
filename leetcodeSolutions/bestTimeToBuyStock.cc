class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size()<=1) return 0;
        
        vector<int> minBefore(prices.size());
        
        minBefore[0] = prices[0];
        
        for(int i=1;i<prices.size();++i){
            minBefore[i] = min(prices[i],minBefore[i-1]);
        }
        
        int ans=0;
        
        for(int i=0;i<prices.size();++i){
            ans = max(ans,prices[i]-minBefore[i]);
        }
        
        return ans;
    }
};
