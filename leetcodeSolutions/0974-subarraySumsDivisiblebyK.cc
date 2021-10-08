class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //  here, we want prefix[r] - prefix[l] = n*k; n ε I+
        //  taking mod with k
        //  prefix[r] % k - prefix[l] % k = 0
        //  prefix[r] % k = prefix[l] % k
        int preSum = 0;
        
        vector<int> fa(k);    //  we will be doing mod, so k is the upperbound
        ++fa[0];
        
        int ans = 0;
        
        for(int i=0;i<nums.size();++i){
            preSum = (preSum + (nums[i] % k)) % k;  //  getting the prefixSum
            
            if(preSum<0) preSum += k;   //  handling negative numbers
            
            ans += fa[preSum];  //  matching the current remainder to all other and adding to the final answer
            
            ++fa[preSum];   //  increasing the current count of the remainder
        }
        
        return ans;
    }
};
