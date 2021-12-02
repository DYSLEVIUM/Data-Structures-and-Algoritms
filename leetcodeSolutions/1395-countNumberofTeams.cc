//  O(n^2)
// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int ans = 0;
        
//         for(int i=1;i<rating.size()-1;++i){
            
//             int less[2] = {}, greater[2] = {};
            
//             for (auto j = 0; j < rating.size(); ++j) {
//                 if (rating[i] < rating[j]) ++less[j > i];
//                 if (rating[i] > rating[j]) ++greater[j > i];
//             }
            
//             ans += less[0] * greater[1] + greater[0] * less[1]; //  leftSmaller * rightLarger + leftLarger * rightSmaller
//         }
        
//         return ans;
//     }
// };

//  https://www.cnblogs.com/lz87/p/12602969.html
//  O(n log n)
class Solution {
public: 
    class BinaryIndexedTree {
        vector<int> _data;
        size_t _size;

        public:
        BinaryIndexedTree(int n):_size(n+1) {
            this->_data.assign(this->_size, 0);
        }

        int query(int x) {
            int sum = 0;
            while(x>0){
                sum += this->_data[x];
                x -= (x&-x);
            }
            
            return sum;
        }

        void update(int x, const int& delta) {
            while(x<this->_size){
                this->_data[x] += delta;
                x +=(x&-x);
            }
        }
    };
    
    int numTeams(vector<int>& rating) {
        int maxi = *max_element(rating.begin(), rating.end());
        
        auto solve = [&maxi](const vector<int>& rating) {
            BinaryIndexedTree bit1(maxi);
            BinaryIndexedTree bit2(maxi);

            int currAns = 0;
            for(int i = 0; i < rating.size(); i++) {
                currAns += bit1.query(rating[i] - 1);
                
                bit1.update(rating[i], bit2.query(rating[i] - 1));
                bit2.update(rating[i], 1);
            }
            return currAns;
        };
        
        return solve(rating) + solve(vector<int>(rating.rbegin(), rating.rend()));
    }
};
