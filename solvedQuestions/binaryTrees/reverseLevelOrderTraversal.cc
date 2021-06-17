vector<int> reverseLevelOrder(Node *root)
{
    
    vector<int> ans;
    
    if(root==NULL) return ans;
    
    queue<Node*> q;
    
    q.push(root);
    
    while(!q.empty()){
        Node *f = q.front();
        q.pop();
        
        ans.push_back(f->data);
        
        if(f->right!=NULL){
            q.push(f->right);
        }
        
        if(f->left!=NULL){
            q.push(f->left);
        }
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}
