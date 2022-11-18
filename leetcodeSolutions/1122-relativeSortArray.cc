class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n2 = arr2.size();
        unordered_map<int, int> weight;
        for(int i = 0; i < n2; ++i) weight[arr2[i]] = i;

        sort(arr1.begin(), arr1.end(), [&](const int &lhs, const int &rhs){
            if(!weight.count(lhs)) weight[lhs] = n2;
            if(!weight.count(rhs)) weight[rhs] = n2;

            if(weight[lhs] == weight[rhs]) return lhs < rhs;
            return weight[lhs] < weight[rhs];
        });

        return arr1;
    }
};
