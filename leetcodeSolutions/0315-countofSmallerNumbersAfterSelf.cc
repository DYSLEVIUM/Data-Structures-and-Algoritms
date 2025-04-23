#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

template <typename T>
class FenwickTree{
    size_t size;
    vector<T> bit;

    public:
    FenwickTree(const int & sz): size(sz), bit(sz) {    }

    void update(int idx, const T & delta) {
        ++idx;

        while(idx < bit.size()) {
            bit[idx] += delta;
            idx += (idx & -idx);
        }
    }

    T query(int idx) {
        ++idx;

        T val = 0;
        while(idx > 0) {
            val += bit[idx];
            idx -= (idx & -idx);
        }

        return val;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        static constinit const int TRANSLATE = 1e4 + 1;
        
        const int n = nums.size();

        vector<int> ans(n);
        FenwickTree<int> bit(TRANSLATE << 1);
        for(int i = n - 1; i >= 0; --i) {
            int new_num = nums[i] + TRANSLATE;

            ans[i] = bit.query(new_num - 1);
            bit.update(new_num, 1);
        }

        return ans;
    }
};
