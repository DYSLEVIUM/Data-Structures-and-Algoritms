// class Solution {
// public:
//     bool primeSubOperation(vector<int>& nums) {
//         int n = *max_element(nums.begin(), nums.end()) + 1;

//         vector<bool> sieve(n, 1);
//         sieve[0] = sieve[1] = 0;
//         for(int i = 2; i * i < n; ++i) {
//             if(!sieve[i]) {
//                 continue;
//             }

//             for(int j = i * i; j < n; j += i) {
//                 sieve[j] = 0;
//             }
//         }

//         vector<int> primes;
//         primes.reserve(n);
//         for(int i = 0; i < n; ++i){
//             if(sieve[i]) {
//                 primes.push_back(i);
//             }
//         }

//         int maxx = 0;
//         for(int & num : nums) {
//             // optimal conditions for greedy
//             // num - x > maxx;
//             // x < num; x is the greatest prime

//             // finding the greatest prime, if we don't get we give up!
//             int curr = 0;
//             for(const int & prime : primes) {
//                 if(num - prime <= maxx) {
//                     break;
//                 }
//                 curr = prime;
//             }

//             // greedily making the modifications
//             num -= curr;

//             // not possible case
//             if(maxx >= num) {
//                 return false;
//             }

//             maxx = max(maxx, num);
//         }

//         return true;
//     }
// };
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end()) + 1;

        vector<bool> sieve(n, 1);
        sieve[0] = sieve[1] = 0;
        for(int i = 2; i * i < n; ++i) {
            if(!sieve[i]) {
                continue;
            }

            for(int j = i * i; j < n; j += i) {
                sieve[j] = 0;
            }
        }

        set<int> primes;
        for(int i = 0; i < n; ++i){
            if(sieve[i]) {
                primes.insert(i);
            }
        }

        primes.insert(0); // for edge case on lower_bound

        int maxx = 0;
        for(int & num : nums) {
            // optimal conditions for greedy
            // num - x > maxx;
            // x < num; x is the greatest prime

            int curr = *prev(primes.lower_bound(num - maxx)); // finding the greatest prime
            num -= curr; // greedily making the modifications

            if(maxx >= num) { // not possible case
                return false;
            }

            maxx = num;
        }

        return true;
    }
};
