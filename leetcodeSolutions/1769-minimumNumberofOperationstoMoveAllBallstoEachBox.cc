class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int n = boxes.size();

        vector<int> ans(n, 0);
        
        int sum;
        
        sum = boxes[0]-'0'; // if the initial has a ball, we count it for the next iteration
        // prefix
        for(int i=1;i<n;++i){
            ans[i] += ans[i-1]+sum; // cost to bring all the balls to the previous box + total balls
            sum+=(boxes[i]-'0');
        }
        
        int last_cost = 0;  // to keep track of the total balls shifted, as we don't want to ruin the prefix or use O(N) space
        sum = boxes[n-1]-'0';
        // suffix
        for(int i=n-2;i>=0;--i){
            ans[i] += sum+last_cost;
            last_cost+=sum;
            sum+=(boxes[i]-'0');
        }
        
        return ans;
    }
};
