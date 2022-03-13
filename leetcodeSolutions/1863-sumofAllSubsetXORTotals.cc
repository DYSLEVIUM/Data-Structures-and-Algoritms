class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
      int n = nums.size();
      
      //  Time: O(n)
      /*  Explanation:
          We can conclude that in all subsets of an n-number array, each number appears exactly 2 << (n-1) times, but that does not lead to the conclusion that each bit appears 2 << (n-1) times, at least directly. So, we still need to prove this observation.
Without loss of generality, let's focus on the i-th bit of all elements. We can suppose x of them are 1 and y of them are 0, so that x + y = n. The i-th bits of n numbers produce a sequence like this:

1,1,1,...,1,0,0,0,...,0
----------- -----------
    x            y
We want to prove that the XOR sum of any non-empty subset of this sequence is exactly 2 ^ (x + y - 1) = 2 ^ (n - 1) as long as x > 0.
Since we need an odd number of 1's in a subset to produce a non-zero result, the problem reduces to what's the number of subsets with an odd number of 1's?
The key is that it has the same answer with its dual problem: what's the number of subsets (including the empty set) with an even number of 1's? (For a proof, please refer to this StackExchange answer: https://math.stackexchange.com/q/1338830)
Since there are 2^n subsets in total, the answer is clearly 2 ^ (n-1).
      */
      //  (or of all the numbers) ^ (n-1)
      return accumulate(nums.begin(), nums.end(), 0, bit_or<int>()) << (n - 1);

      //  Time: O(2^(n-1))
//       int ans = 0;
//       int mask = (1 << n);
//       for(int i = 0; i < mask; ++i){
//         int temp = i;
//         int iter = 0;
        
//         int curr_ans = 0;
//         while(temp){
//           if(temp & 1) curr_ans ^= nums[iter];
          
//           ++iter;
//           temp >>= 1;
//         }
//         ans += curr_ans;
//       }
      
//       return ans;
    }
};
