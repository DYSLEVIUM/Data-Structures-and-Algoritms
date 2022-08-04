//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


// } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

// O(n^2)
class Solution1 {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        if(!root) {
            return false;
        }
        
        auto is_same = [](const auto &is_same, Node * const &node1, Node * const &node2){
            if(!node1 && !node2) {
                return true;
            }
            
            if(!node1 || !node2) {
                return false;
            }
            
            return node1->data == node2->data && is_same(is_same, node1->left, node2->left) && is_same(is_same, node1->right, node2->right);
        };
        
        vector<Node *> nodes;
        auto dfs = [&](const auto &dfs, Node * const &node){
            if(!node) {
                return ;
            }
            
            // not inserting leaf nodes, as the size should be more than 1
            if(node->left || node->right) {
                nodes.push_back(node);            
            }
            
            dfs(dfs, node->left);
            dfs(dfs, node->right);
        };
        dfs(dfs, root);
        
        for(auto &node1 : nodes) {
            for(auto &node2 : nodes) {
                if(node1 == node2) {
                    continue;
                }
                
                if(is_same(is_same, node1, node2)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        char MARKER = '#';
        unordered_set<string> subtrees;
        auto dupSubUtil = [&](const auto &dupSubUtil, Node * const &node) -> string {
            string s = "";
            
            if(!node) {
                return (s + MARKER);
            }
            
            // found answer from left side
            string l_str = dupSubUtil(dupSubUtil, node->left);
            if(l_str.compare(s) == 0) {
                return s;
            }

            // found answer from right side
            string r_str = dupSubUtil(dupSubUtil, node->right);
            if(r_str.compare(s) == 0) {
                return s;
            }
            
            // serialize string
            s = s + node->data + l_str + r_str;
            
            // found answer
            if(s.length() > 3 && subtrees.count(s)) {
                return "";
            }
            
            subtrees.insert(s);
            
            return s;
        };
        string str = dupSubUtil(dupSubUtil, root);
        
        return str.compare("") == 0;
    }
};


//{ Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}
// } Driver Code Ends
