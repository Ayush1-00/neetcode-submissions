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
    int findLen(ListNode* head){
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=findLen(head);
        int tar=len-n+1;
        int count=1;
        if(tar==1)return head->next;
        ListNode* pre=NULL;
        ListNode* curr=head;
        while(count!=tar){
            count++;
            pre=curr;
            curr=curr->next;
        }
        pre->next=curr->next;
        curr->next=NULL;
        delete curr;
        return head;
    }
};
