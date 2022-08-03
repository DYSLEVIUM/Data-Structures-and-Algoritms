//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n) {
        // inorder -> LDR
        // preorder -> DLR
        
        unordered_map<int, int> pre_in;
        for(int i = 0; i < n; ++i) {
            pre_in[in[i]] = i;
        }
        
        auto make_tree = [&](const auto &make_tree, int &pr_ptr, const int &i_l, const int &i_r) -> Node * {
            if(pr_ptr == n || i_l > i_r) {
                return nullptr;
            }
            
            int node_val = pre[pr_ptr];
            ++pr_ptr;
            
            Node *node = new Node(node_val);
            
            node->left = make_tree(make_tree, pr_ptr, i_l, pre_in[node_val] - 1);
            node->right = make_tree(make_tree, pr_ptr, pre_in[node_val] + 1, i_r);
            
            return node;
        };
        
        int pr_ptr = 0;
        return make_tree(make_tree, pr_ptr, 0, n - 1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
