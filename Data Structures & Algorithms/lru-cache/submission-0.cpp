class Node{
    public:
    int val;
    int key;
    Node* next;
    Node* pre;
    Node(int val,int key){
        this->val=val;
        this->key=key;
        next=NULL;
        pre=NULL;
    }
};
class LRUCache {
    unordered_map<int,Node*>m;
    Node* head;
    Node* tail;
    int cap;
    void remove(Node* temp){
        temp->pre->next=temp->next;
        temp->next->pre=temp->pre;
        temp->next=NULL;
        temp->pre=NULL;
    }
    void insert(Node* temp){
        tail->pre->next=temp;
        temp->pre=tail->pre;
        tail->pre=temp;
        temp->next=tail;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new  Node(-1,-1);
        head->next=tail;
        tail->pre=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())return -1;
        else{
            Node* temp=m[key];
            remove(temp);
            insert(temp);
            return temp->val;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* temp=m[key];
            remove(temp);
            temp->val=value;
            insert(temp);
        }
        else{
            if(m.size()<cap){
                Node* temp=new Node(value,key);
                m[key]=temp;
                insert(temp);
            }
            else{
                
                m.erase(head->next->key);
                remove(head->next);
                Node* temp=new Node(value,key);
                m[key]=temp;
                insert(temp);
            }
        }
    }
};
