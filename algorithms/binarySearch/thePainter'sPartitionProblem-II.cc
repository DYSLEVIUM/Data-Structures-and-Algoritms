// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        auto check = [&](const long long &x){
            long long cnt = 0;
            long long sum = 0;
            for(long long i = 0; i < n; ++i) {
                sum += arr[i];
                if(sum > x) {
                    ++cnt;
                    sum = arr[i];
                }
            }
            
            //  we will have k - 1 partition points
            return cnt < k;
        };
        
        long long lo = *max_element(arr, arr + n), hi = accumulate(arr, arr + n, 0LL);
        while(lo < hi) {
            long long mid = lo + ((hi - lo) >> 1);
            
            if(check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends
