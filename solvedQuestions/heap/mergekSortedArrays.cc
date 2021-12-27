// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        vector<int> res;
        
        //  this stores the current column count of each row
        vector<int> col_cnt(k, 0);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        //  adding all the first column elements
        for(int i=0;i<k;++i) min_heap.push({arr[i][0], i});
        
        while(!min_heap.empty()){
            pair<int, int> tp = min_heap.top();
            min_heap.pop();
            
            res.push_back(tp.first);
            int c = tp.second;
            
            //  next column of this row
            ++col_cnt[c];
            
            //  if this column exists, then add this number to heap
            if(col_cnt[c]<k) min_heap.push({arr[c][col_cnt[c]], c});
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends
