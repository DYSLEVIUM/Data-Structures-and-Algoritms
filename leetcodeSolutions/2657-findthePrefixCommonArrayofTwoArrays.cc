class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> C(n);
        bitset<64> a_mask, b_mask;
        for(int i = 0; i < n; ++i) {
            a_mask.set(A[i]), b_mask.set(B[i]);
            C[i] = __builtin_popcountll(a_mask.to_ullong() & b_mask.to_ullong());
        }

        return C;
    }
};
