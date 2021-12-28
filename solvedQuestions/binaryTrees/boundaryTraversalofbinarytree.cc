// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        
        vector<int> res;
        
        if(!root) return res;
        
        res.push_back(root->data);
  
        //  all left node
        auto get_left = [&res](const auto& get_left, const Node* const node)->void{
            if(!node) return;
            
            if(node->left){
                res.push_back(node->data);
                get_left(get_left, node->left);
            }
            else if(node->right) {
                res.push_back(node->data);
                get_left(get_left, node->right);
            }
            
            //  do nothing for leaf node
        };
        get_left(get_left, root->left);
        
        //  all leaf nodes
        auto dfs = [&res](const auto& dfs, Node* node)->void{
            if(!node) return;
            
            dfs(dfs, node->left);
            
            if(!node->right && !node->left) res.push_back(node->data);
            
            dfs(dfs, node->right);
        };
        dfs(dfs, root->left);
        dfs(dfs, root->right);
        
        //  all right nodes in reverse
        auto get_right = [&res](const auto& get_right, const Node* const node)->void{
            if(!node) return;
            
            if(node->right) {
                get_right(get_right, node->right);
                res.push_back(node->data);
            }
            else if(node->left){
                get_right(get_right, node->left);
                res.push_back(node->data);
            }
            
            //  do nothing for leaf node
        };
        get_right(get_right, root->right);

        return res;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
