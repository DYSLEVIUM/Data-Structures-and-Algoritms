// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int ternarySearch(int arr[], int N, int K) 
    { 
       // Your code here
       int lo = 0, hi = N - 1;
       while(lo <= hi) {
           int seg_len = (hi - lo) / 3;
           int mid_l = lo + seg_len;
           int mid_r = hi - seg_len;
           
           if(arr[mid_l] == K || arr[mid_r] == K) {
                return 1;
           } else if(K < arr[mid_l]) {
                hi = mid_l - 1;
           } else if(K > arr[mid_r]) {
                lo = mid_r + 1;
           } else {
                lo = mid_l + 1, hi = mid_r - 1;
           }
       }
       
       return -1;
    }
};

// { Driver Code Starts.
int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int N, K;
        cin >> N >> K;
        
        int arr[N];
        
        for(int i = 0;i<N;i++){
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.ternarySearch(arr, N, K) << endl;

    }

	return 0; 
} 
  // } Driver Code Ends
