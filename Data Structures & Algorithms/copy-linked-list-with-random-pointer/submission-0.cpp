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
        Node* ans=new Node(-1);
        Node* curr=ans;
        Node* temp=head;
        while(temp!=NULL){
            Node* nn=new Node(temp->val);
            curr->next=nn;
            curr=nn;
            temp=temp->next;
        }
        ans=ans->next;
        Node* c1=head;
        Node* c2=ans;
        while(c1&&c2){
            Node* f=c1->next;
            c1->next=c2;
            Node* f2=c2->next;
            c2->next=f;
            c1=f;
            c2=f2;
        }
        c1=head;
        while(c1){
            if(c1->random)c1->next->random=c1->random->next;
            c1=c1->next->next;
        }
        c1=head;
        c2=ans;
        while(c1&&c2){
            c1->next=c2->next;
            Node* f=c1->next;
             if (f)
        c2->next = f->next;
    else
        c2->next = NULL;
            c1=f;
            c2=c2->next;
        }
        return ans;
    }
};
