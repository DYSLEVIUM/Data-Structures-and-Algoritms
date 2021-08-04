// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        auto addOne = [](Node*& currNode, const auto& addOne){
            if(currNode->next==NULL){
                if(currNode->data==9){
                    currNode->data=0;
                    return true;
                }else{
                    currNode->data+=1;
                    return false;
                }
            }
            
            if(addOne(currNode->next, addOne)){
                
                if(currNode->data==9){
                    currNode->data=0;
                    return true;
                }else{
                    currNode->data+=1;
                    return false;
                } 
            }
        };
        
        if(addOne(head, addOne)){
            Node* newNode = new Node(0);
            Node* temp = head->next;
            
            head->next=newNode;
            newNode->next=temp;
            
            head->data=1;
            
            temp=head->next;
            while(temp!=NULL){
                temp->data=0;
                temp=temp->next;
            }
        }
        
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
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
