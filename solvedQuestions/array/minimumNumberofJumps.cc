// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        //  Time: O(n*n)
        //  Space: O(n)
        // vector<int> dp(n, INT_MAX/2);
        // dp[0] = 0;
        
        // for(int i=1;i<n;++i){   //  i is the target index for each state
        //     for(int j=0;j<i;++j){   //  for all the previous indicies
        //         if(arr[j]>=i-j) dp[i] = min(1+dp[j], dp[i]);    //  if we can reach the target, get the minimum steps required from previous minimum or the 1+current state
        //         else dp[i] = min(dp[i], INT_MAX/2); //  cannot reach the target
        //     }
        // }
        
        // if(dp[n-1]==INT_MAX/2) return -1;
        
        // return dp[n-1];
        
        //  Time: O(n)
        //  Space: O(1)
        
        if(n==1) return 0;
        
        if(arr[0]==0) return -1;
        
        int maxReach=arr[0];
        int step=arr[0];
        int jump=1;
        
        if(maxReach>=n-1) return jump;  //  if can reach end from the very first element
        
        //  if we are at n-1 we have to break as we reached the end
        for(int i=1;i<n-1;++i){
            maxReach = max(maxReach, i+arr[i]);
            
            if(maxReach>=n-1) return jump+1;    //  we can reach if we make one jump
            
            --step; //  for consideration of all the other cases making one step at a time
            
            //  if can't get to the end with the current max, forces to make a jump
            if(step==0){
                // cout<<i<<'\n';  //  position where jumps were made
                if(i>=maxReach) return -1;
                ++jump;
                
                step=maxReach-i;    //  we get the previous maxReach and remove the total step we made to get to this index, i.e., i
            }
        }
        
        return jump;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
