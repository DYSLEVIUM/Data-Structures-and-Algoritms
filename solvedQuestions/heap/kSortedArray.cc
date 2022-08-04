//{ Driver Code Starts
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
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        vector<int> rows_col_ptr(k, 0);
        
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> min_heap;
        
        for(int i = 0; i < k; ++i) {
            min_heap.push({arr[i][0], i});
        }
        
        vector<int> ans;
        while(!min_heap.empty()) {
            PII tp = min_heap.top();
            min_heap.pop();
            
            ans.push_back(tp.first);
            
            int curr_row = tp.second;
            ++rows_col_ptr[curr_row]; // moving the pointer of this row forward
            
            if(rows_col_ptr[curr_row] < k) {
                min_heap.push({arr[curr_row][rows_col_ptr[curr_row]], curr_row});
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
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
