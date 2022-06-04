// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> vec, int k) {
    //code here
    int n = vec.size();
    int lo = 0, hi = n - 1;
    while(lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        
        if(vec[mid] == k) return mid;
        
        if(vec[lo] < vec[mid]) {
            if(k >= vec[lo] && k < vec[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else if(vec[mid] < vec[hi]) {
            if(k > vec[mid] && k <= vec[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        } else {
            ++lo;
        }
    }
    
    return -1;
}
