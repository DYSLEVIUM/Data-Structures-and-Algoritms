//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        if(n == 0 || n == 1) {
            return n;
        }
        
    	vector<pair<int, int>> trains(n);
    	for(int i = 0; i < n; ++i) {
    	    trains[i] = { dep[i], arr[i] };
    	}
    	
    	sort(trains.begin(), trains.end());
    	
    	int ans = INT_MIN;
    	for(int i = 0; i < n; ++i) {
    	    int curr_cnt = 1, j = i + 1, curr_max_time = trains[i].first;
    	    
    	    while(j < n && trains[j].second >= curr_max_time) {
    	        ++j, ++curr_cnt;
    	        curr_max_time = max(curr_max_time, trains[j].first);
    	    }
    	    i = j - 1;
    	    
    	    ans = max(ans, curr_cnt);
    	}
    	
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
