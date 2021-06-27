// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
    // Complet the function
    int cnt = 0;

    for (int i = 0; i < n; ++i) cnt += (arr[i] <= k);

    int bad = 0;
    for (int i = 0; i < cnt; ++i) bad += (arr[i] > k);

    int ans = bad;

    for (int i = 0, j = cnt; j < n; ++i, ++j) {
      if (arr[i] > k) --bad;
      if (arr[j] > k) ++bad;

      ans = min(ans, bad);
    }

    return ans;
}
