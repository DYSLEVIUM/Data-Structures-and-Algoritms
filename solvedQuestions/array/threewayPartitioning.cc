// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here
        // int p1=0;
        // for(int i=0;i<array.size();++i){
        //     if(i==p1) continue;
            
        //     if(array[i]<a){
        //         swap(array[i], array[p1]);
            
        //         ++p1;
        //         --i;
        //     }
        // }
        
        // int p2=array.size()-1;
        // for(int i=0;i<array.size();++i){
        //     if(i==p2) break;    //  breaking so that we don't get stuck in a loop
            
        //     if(array[i]>b){
        //         swap(array[i], array[p2]);
                
        //         --p2;
        //         --i;
        //     }
            
        // }
        
        //   Dutch National Flag based QuickSort
        int start = 0, end = array.size()-1;
        
        //  we keep moving the pointers from the left and the right, gradually decreasing the range
        for(int i=0;i<end+1;){
            if(array[i]<a) swap(array[i++], array[start++]);
            else if(array[i]>b) swap(array[i], array[end--]);
            else ++i;
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        
        vector<int> array(N);
        unordered_map<int,int> ump;
        
        for(int i=0;i<N;i++){
            cin>>array[i];
            ump[array[i]]++;
        }
        
        int a,b;
        cin>>a>>b;
        
        vector<int> original = array;

        int k1=0,k2=0,k3=0;
        int kk1=0;int kk2=0;int kk3=0;
        
        for(int i=0; i<N; i++)
        {
            if(original[i]>b)
                k3++;
            else if(original[i]<=b and original[i]>=a)
                k2++;
            else if(original[i]<b)
                k1++;
        }
        
        Solution ob;
        ob.threeWayPartition(array,a,b);
      
        for(int i=0;i<k1;i++)
        {
            if(array[i]<b)
            kk1++;
        }
        
        for(int i=k1;i<k1+k2;i++)
        {
            if(array[i]<=b and array[i]>=a)
            kk2++;
            
        }
        
        for(int i=k1+k2;i<k1+k2+k3;i++)
        {
            if(array[i]>b)
            kk3++;
        }
        bool ok = 0;
        if(k1==kk1 and k2 ==kk2 and k3 == kk3)
            ok = 1;
        
        for(int i=0;i<array.size();i++)
            ump[array[i]]--;
        
        for(int i=0;i<array.size();i++)
            if(ump[array[i]]!=0)
                ok=0;
        
        if(ok)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        
    }
    
    return 0;
}
  // } Driver Code Ends
