class Node{
    public:
    int val;
    int key;
    Node* next;
    Node* prev;
    
    Node(int x,int k)
    {
        val=x;
        key=k;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*>m;
    Node* head=new Node(-1,-1),*tail=new Node(-1,-1);
    int size;
    
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        
        Node* temp=m[key];
        
        //delete node
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        
        //insert at head
        temp->next=head->next;
        head->next->prev=temp;
        temp->prev=head;
        head->next=temp;
        
        return temp->val;
    }
    
    void put(int key, int value) {
        Node* node=new Node(value,key);
        
        if(m.find(key)!=m.end())
        {
            Node* temp=m[key];
            m.erase(key);
            
            //delete node
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            
            //insert at head
            node->next=head->next;
            head->next->prev=node;
            node->prev=head;
            head->next=node;
            
            m[key]=node;
        }
        else
        {
            if(m.size()<size)
            {
                //insert at head
                node->next=head->next;
                head->next->prev=node;
                node->prev=head;
                head->next=node;
                
                m[key]=node;
            }
            else
            {
                Node* temp=tail->prev;
                m.erase(temp->key);
                
                //delete node
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                
                //insert at head
                node->next=head->next;
                head->next->prev=node;
                node->prev=head;
                head->next=node;
                
                m[key]=node;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */