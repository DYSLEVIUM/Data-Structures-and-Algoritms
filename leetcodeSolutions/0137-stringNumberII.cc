class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> num(32,0);
        
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<num.size();j++){
                num[j]+=(nums[i]&1);
                nums[i]>>=1;
            }
        }
        
        long long ans=0;
        for(int i=0;i<num.size();++i){
            if(num[i]-1>=0 && (num[i]-1)%3==0)
                ans+=pow(2,i);
        }
        
        return ans;
    }
};
