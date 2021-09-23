//https://leetcode.com/problems/find-the-duplicate-number/solution/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[abs(nums[i]) - 1] < 0)
//                 return abs(nums[i]);
//             else
//                 nums[abs(nums[i]) - 1] *= -1;
//         }
//         return -1;
        
        int turtle = nums[0];   // slow pointer
        int hare = nums[0]; // fast pointer
        
        // find the intersection point of the two pointers
        do{
            turtle = nums[turtle];  // moving one point forward
            hare = nums[nums[hare]];    // moving two points forward
        }while(turtle!=hare);
        
        //  slow pointer should again start from first and continue while we don't reach the position where the slow and the fast pointer meet, when we reach the same position; that will be the begining of the loop
        turtle = nums[0];
        while(turtle!=hare){
            turtle = nums[turtle];
            hare = nums[hare];
        }
        
        return hare;
    }
};
