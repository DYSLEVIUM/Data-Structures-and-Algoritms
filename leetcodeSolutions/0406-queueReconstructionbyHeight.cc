template <typename T>
class FenwickTree {
public:
  FenwickTree (const size_t &sz): m_size(sz) {
    m_data.assign(m_size, 0);
  }
  
  T query(size_t x) {
    T val = 0;
    while(x > 0) {
      val += m_data[x];
      x -= (x & -x);
    }
    return val;
  }

  void update(size_t x, const T& delta) {
    while(x < m_size) {
      m_data[x] += delta;
      x += (x & -x);
    }
  }
private:
  size_t m_size;
  vector<T> m_data;
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      int n = people.size();
      FenwickTree<int> bit(n + 1);
      
      //  number of empty spaces left in front
      for(int i = 2; i < n + 1; ++i) {
        bit.update(i, 1);
      }

      //  if height is same, first place the one on the extreme left
      sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b){
        if(a[0] == b[0]) {
          return a[1] > b[1];
        }
        return a[0] < b[0];
      });
      vector<vector<int>> res(n);
      for(vector<int> &person: people) {
        //  finding the position to place the element
        int lo = 0, hi = n - 1;
        while(lo < hi) {
          int mid = lo + ((hi - lo) >> 1);

          //  less spaces left on the left
          if(bit.query(mid + 1) < person[1]) {
            lo = mid + 1;
          } else {
            hi = mid;
          }
        }
        
        //  we get the valid upperbound position, that's why we sorted it with greatest k first
        res[lo] = person;
        bit.update(lo + 1, -1); //  updating the BIT, by stating we consumend one space
      }
      
      return res;
    }
};
