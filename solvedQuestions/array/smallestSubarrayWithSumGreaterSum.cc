// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here   
        int curr = 0;
        int ans = INT_MAX;
        
        int p1=0;
        int p2=0;
        
        int sum = arr[p1];
        
        //  sliding window ninja technique
        while(p2>=p1 && p2<n && p1<n){
            if(sum>x){
                ans = min(ans, p2-p1+1);
            
                //  removing the left element
                sum-=arr[p1];
              
                ++p1;
            }else{
                if(p2+1<n) sum+=arr[p2+1];  //  adding the right element
                ++p2;
            }
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends
