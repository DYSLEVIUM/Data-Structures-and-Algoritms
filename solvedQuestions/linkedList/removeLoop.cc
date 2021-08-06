// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


 // } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
#include<bits/stdc++.h>

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        
        //  Time O(n)
        //  Space O(n)
        
        // unordered_set<Node *> se;
        
        // while(head!=NULL){
        //     if(se.find(head->next)==se.end()){
        //         se.insert(head);
        //     }else{
        //         head->next=NULL;
        //     }
        //     head=head->next;
        // }
        
        //  Time O(n)
        //  Space O(1)
        auto removeLoop = [&head](Node* loopNode){
            Node* p1 = loopNode;
            Node* p2 = loopNode;
            
            //  count the number of nodes in the loop
            int k=1, i;
            while(p1->next!=p2){
                p1=p1->next;
                ++k;
            }
            
            //  fix one pointer to headd
            p1=head;
            
            //  other pointer to k nodes after head
            p2=head;
            while(k--) p2=p2->next;
            
            //  move both the pointers at the same pace, they will meet at the loop starting node
            while(p2!=p1){
                p1=p1->next;
                p2=p2->next;
            }
            
            //  get pointer to the last node
            while(p2->next!=p1) p2=p2->next;
            
            //  remove the loop
            p2->next=NULL;
        };
        
        auto detectandRemove = [&head, &removeLoop](){
            Node *slow = head, *fast = head;
        
            while(fast!=NULL && slow!=NULL && fast->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow==fast){
                    removeLoop(slow);
                    return;
                }
            }
        };
        
        detectandRemove();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
  // } Driver Code Ends
