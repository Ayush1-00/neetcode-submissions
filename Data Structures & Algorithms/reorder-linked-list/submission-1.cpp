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
    ListNode* reverse(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* f=curr->next;
            curr->next=pre;
            pre=curr;
            curr=f;
        }
        return pre;
    }
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)return;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL; 
        while(fast!=NULL&&fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode* mid=slow;
        mid=reverse(mid);
        ListNode* t1=head->next;
        ListNode* t2=mid;
        ListNode* temp=head;
        while(t1){
            temp->next=t2;
            t2=t2->next;
            temp=temp->next;
            temp->next=t1;
            t1=t1->next;
            temp=temp->next;
        }
        if(t2)temp->next=t2;
        
        
        
        
    }
};
