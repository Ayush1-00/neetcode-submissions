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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* tail=ans;
        ListNode* t1=l1;
        ListNode* t2=l2;
        int carry=0;
        while(carry||t1||t2){
            int tar=carry;
            if(t1){
                tar+=t1->val;
                t1=t1->next;
            }
            if(t2){
                tar+=t2->val;
                t2=t2->next;
            }
            int digit=tar%10;
            carry=tar/10;
            tail->next=new ListNode(digit);
            tail=tail->next;
        }
        return ans->next;
    }
};
