class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        
        if (root==NULL) return 0;
        
        int dia = 0;
        
        //  we check at every node if we have a greater diameter
        auto findHeight = [&dia](Node* node, auto&& findHeight)->int{
            if(!node) return 0;
            
            int l = findHeight(node->left, findHeight);
            int r = findHeight(node->right, findHeight);
            
            dia = max(dia, 1+l+r);
            
            return 1+max(l,r);
        };
        
        dia = max(dia, findHeight(root, findHeight));
        
        return dia;
    }
};
