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
        int count =k;
        ListNode* temp=head;
        while(count){
            if(temp==NULL)return head;
            temp=temp->next;
            count--;
        }
        count=k;
        ListNode* pre=NULL;
        ListNode* curr=head;
        while(count){
            ListNode* f=curr->next;
            curr->next=pre;
            pre=curr;
            curr=f;
            count--;
        }
        if(curr)head->next=reverseKGroup(curr,k);
        return pre;
    }
};
