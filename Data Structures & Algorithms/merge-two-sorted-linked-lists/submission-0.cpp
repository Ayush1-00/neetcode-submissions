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
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* t1=head1->next;
        ListNode* t2=head2;
        ListNode* ans=head1;
        while(t1!=NULL&&t2!=NULL){
            if(t1->val<=t2->val){
                ans->next=t1;
                t1=t1->next;
                ans=ans->next;
            }
            else{
                ans->next=t2;
                t2=t2->next;
                ans=ans->next;
            }
        }
        if(t1)ans->next=t1;
        if(t2)ans->next=t2;
        return head1;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1->val <= list2->val)return merge(list1,list2);
        else return merge(list2,list1);
    }
};
