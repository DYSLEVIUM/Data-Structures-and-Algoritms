//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends

// we use bit mask to store the minimum in the lower half of the 16 bits
void push(stack<int>& s, int a){
    int mini, new_a;
    if(s.empty()) {
        mini = a;
    } else {
        int mask = (1 << 16) - 1;
        mini = min(s.top() & mask, a);
    }
    new_a = (a << 16) | mini;
    
    s.push(new_a);
}

bool isFull(stack<int>& s,int n){
    return s.size() == n;
}

bool isEmpty(stack<int>& s){
    return s.empty();
}

int pop(stack<int>& s){
    int val = s.top();
    s.pop();
    
    return (val >> 16);
}

int getMin(stack<int>& s){
    int mask = (1 << 16) - 1;
    int mini = s.top() & mask;

    return mini;
}
