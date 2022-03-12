/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      if(!head) return nullptr;
      
      //  interleave the new nodes to the current node
      Node *node = head;
      while(node){
        Node *original_next_node = node->next;
       
        Node *new_node = new Node(node->val);
        node->next = new_node;  //  this is the new node
        
        new_node->next = original_next_node;  //  interleaving
        node = original_next_node;
      }
      
      //  in this pass, we will fix the random pointer
      node = head;
      while(node){
        Node *next_node = node->next;
        //  fixing the random pointer
        next_node->random = node->random ? node->random->next : nullptr;
        node = next_node->next;
      }

      Node* new_head = head->next;
      //  in this pass we will fix the next pointer of both the lists
      node = head;
      while(node){
        Node *next_node = node->next;
        Node *original_next = next_node->next;
        
        node->next = original_next; // fixing the original list
        next_node->next = original_next ? original_next->next : nullptr;  //  fixing the new list
        
        node = original_next;
      }
      
      return new_head;

//       Node *node = head;
//       unordered_map<Node *,Node *> mp;
//       //  just making the new nodes and keeping a reference of what node lead to it
//       while(node){
//         mp[node] = new Node(node->val);
//         node = node->next;
//       }
      
//       node = head;
//       while(node){
//         mp[node]->next = mp[node->next];
//         mp[node]->random = mp[node->random];
//         node = node->next;
//       }
      
//       return mp[head];
    }
};
