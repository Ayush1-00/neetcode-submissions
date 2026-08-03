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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return NULL;
        auto cmp = [](ListNode* a,ListNode* b){
            return a->val>b->val;
        };
        priority_queue<ListNode* , vector<ListNode*> , decltype(cmp)>pq(cmp);
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)pq.push(lists[i]);
        }
        ListNode* ans=new ListNode(-1);
        ListNode* cur=ans;
        while(!pq.empty()){
            ListNode* temp=pq.top();
            pq.pop();
            cur->next=temp;
            cur=cur->next;
            if(temp->next!=NULL)pq.push(temp->next);
            temp->next=NULL;
        }
        return ans->next;
    }
};
