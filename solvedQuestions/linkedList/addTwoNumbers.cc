// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        auto reverseLinkedList = [](Node *&head){
            Node* curr = head;
            Node* next = nullptr;
            Node* prev = nullptr;
            
            while(curr!=NULL){
                next = curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            
            head = prev;
        };
        
        reverseLinkedList(first);
        reverseLinkedList(second);
        
        
        Node* newList = new Node((first->data+second->data)%10);
        int carry = (first->data+second->data)/10;
        
        Node* head = newList;
        
        first=first->next;
        second=second->next;
    
        while(first!=NULL && second!=NULL){
            newList->next = new Node((first->data+second->data+carry)%10);
            carry = (first->data+second->data+carry)/10;
            
            newList=newList->next;
            first=first->next;
            second=second->next;
        }
        
        while(first!=NULL){
            newList->next=new Node((first->data+carry)%10);
            carry = (first->data+carry)/10;
            
            newList=newList->next;
            first=first->next;
        }
        
        while(second!=NULL){
            newList->next=new Node((second->data+carry)%10);
            carry = (second->data+carry)/10;
            
            newList=newList->next;
            second=second->next;
        }
        
        while(carry){
            newList->next=new Node(carry%10);
            carry/=10;
        }
        
        reverseLinkedList(head);
    
        return head;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
