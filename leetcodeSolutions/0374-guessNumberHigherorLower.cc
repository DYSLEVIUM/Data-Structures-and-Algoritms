/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
      int lo = 0, hi = n;
      while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        
        int api_val = guess(mid);
        if(!api_val) return mid;
        else if(api_val == -1) hi = mid - 1;
        else lo = mid + 1;
      }
      
      return -1;
    }
};
