//  https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int inversionPoint =-1;
        
        for(int i=nums.size()-2;i>=0;--i){
            if(nums[i]<nums[i+1]){
                inversionPoint = i;
                break;
            }
        }
        
        if(inversionPoint!=-1){
            for(int i=nums.size()-1;i>=0;--i){
                if(nums[i]>nums[inversionPoint]){
                    swap(nums[i],nums[inversionPoint]);
                    break;
                }
            }    
        }
        
        reverse(nums.begin()+inversionPoint+1,nums.end());            
    }
};
