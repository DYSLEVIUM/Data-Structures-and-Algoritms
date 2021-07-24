// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       // your code here
        vector<int> lisArr;
        lisArr.emplace_back(arr[0]);
        
        for(int i=1;i<n;++i){
            if(lisArr.back()<arr[i]){
                lisArr.emplace_back(arr[i]);
            }else{
                int idx = lower_bound(lisArr.begin(), lisArr.end(), arr[i])-lisArr.begin();
                
                lisArr[idx] = arr[i];
            }
        }
        
        return lisArr.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
