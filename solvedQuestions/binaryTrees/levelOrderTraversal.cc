class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      
      vector<int> res;
      
      if(node==NULL) return res;
      
      queue<Node*> q;
      
      q.push(node);
      
      while(!q.empty()){
        Node* f = q.front();
        q.pop();

        res.push_back(f->data);
        
        if(f->left!=NULL) q.push(f->left);
     
        if(f->right!=NULL) q.push(f->right);
      }
      
      return res;
    }
};
