//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size) {
        // moore voting algorithm
        int cnt = 1, candidate = a[0];
        for(int i = 0; i < size; ++i) {
            if(a[i] == candidate) {
                ++cnt;
            } else {
                --cnt;
            }
            
            if(!cnt) {
                cnt = 1;
                candidate = a[i];
            }
        }
        
        cnt = 0;
        for(int i = 0; i < size; ++i) {
            cnt += candidate == a[i];
        }
        
        if(cnt > size / 2) {
            return candidate;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends
