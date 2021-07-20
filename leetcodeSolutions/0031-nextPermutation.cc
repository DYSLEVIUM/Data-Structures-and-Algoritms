class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int inversionPoint =-1;
        for(int i=nums.size()-2;i>=0;--i){
            //  finding which element is not in order
            if(nums[i]<nums[i+1]){
                inversionPoint = i;
                break;
            }
        }
        
        if(inversionPoint!=-1){
            for(int i=nums.size()-1;i>=0;--i){
                //  finding the position of the just bigger number which we will get first (proved by contradiction)
                if(nums[i]>nums[inversionPoint]){  
                    //  next sequence starts with a[idx2]
                    swap(nums[i],nums[inversionPoint]);
                    break;
                }
            }    
        }
        
        // to get the next permutation, elements after that should be in sorted order || if elements are in reverse order i.e., there is no inversion point, we reverse the whole array
        reverse(nums.begin()+inversionPoint+1,nums.end());            
    }
};
