/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) return head;
        
        ListNode* temp = new ListNode(0);
        temp->next=head;
        
        ListNode* curr=temp, *next=temp, *prev=temp;
        
        int cnt = 0;
        while(curr->next!=NULL){
            ++cnt;
            curr=curr->next;
        }
        
        while(cnt>=k){
            curr=prev->next;
            next=curr->next;
            for(int i=0;i<k-1;++i){
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
            }
            prev=curr;
            cnt-=k;
        }
        
        return temp->next;
    }
};
