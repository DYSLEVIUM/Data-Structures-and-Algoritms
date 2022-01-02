// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        auto is_valid = [&A, &N, &M](const int& x){
            int te_m = M-1; //  already counting for the current student
            int curr = 0;
            
            for(int i=0;i<N;++i){
                curr+=A[i];
                if(curr>x){
                    --te_m;
                    curr=A[i];
                }
            }
            
            return te_m>=0; //  positive amount of students should be left, meaning a smaller answer can be possible
        };
        
        int lo = *max_element(A, A+N);
        int hi = accumulate(A, A+N, 0);
        int ans = -1;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if(is_valid(mid)){
                ans = mid;
                hi = mid - 1;
            }else lo = mid + 1;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
