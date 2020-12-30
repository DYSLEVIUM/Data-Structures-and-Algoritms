class Solution {
public:
    int maxProfit(vector<int>& prices) {

//          O(n) => space
//          O(n) => time
//         if(prices.size()<=1) return 0;
        
//         vector<int> minBefore(prices.size());
        
//         minBefore[0] = prices[0];
        
//         for(int i=1;i<prices.size();++i){
//             minBefore[i] = min(prices[i],minBefore[i-1]);
//         }
        
//         int ans=0;
        
//         for(int i=0;i<prices.size();++i){
//             ans = max(ans,prices[i]-minBefore[i]);
//         }
        
//         return ans;
        
        
//          O(1) => space
//          O(n) => time
        
        int maxProfit = 0;
        int minPrice = INT_MAX;
        
        for(int i=0;i<prices.size();++i){
            if(prices[i]<minPrice){
                minPrice = prices[i];
            }else{
                maxProfit = max(maxProfit,prices[i]-minPrice);
            }
        }
        
        return maxProfit;
    }
};
