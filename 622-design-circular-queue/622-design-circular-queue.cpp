class MyCircularQueue {
public:
    vector<int>ans;
    int size;
    MyCircularQueue(int k) {
        size=k;
    }
    
    bool enQueue(int value) {
        if(ans.size()==size)
           return false;
        ans.push_back(value);
        return true;
    }
    
    bool deQueue() {
      if(ans.size()==0)
          return false;
      ans.erase(ans.begin());
      return true;
    }
    
    int Front() {
       if(ans.size()==0)
           return -1;
        return ans[0];
    }
    
    int Rear() {
        if(ans.size()==0)
            return -1;
        return ans.back();
    }
    
    bool isEmpty() {
       if(ans.size()==0)
           return true;
        return false;
    }
    
    bool isFull() {
        if(ans.size()==size)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */