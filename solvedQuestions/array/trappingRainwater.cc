// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        
        //  max from left
        vector<int> prefix(n);
        prefix[0]=arr[0];
        for(int i=0;i<n;++i) prefix[i] = max(arr[i], prefix[i-1]);
        
        //  max from right
        vector<int> suffix(n);
        suffix[n-1]=arr[n-1];
        for(int i=n-2;i>=0;--i) suffix[i] = max(arr[i], suffix[i+1]);
        
        int ans=0;
    
        for(int i=0;i<n;++i) ans+=min(prefix[i],suffix[i])-arr[i];
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
