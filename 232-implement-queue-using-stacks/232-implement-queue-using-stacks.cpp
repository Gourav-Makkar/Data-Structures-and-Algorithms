class MyQueue {
public:
    int front;
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if (s1.empty())
           front = x;
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int v=s2.top();
        s2.pop();
        return v;
    }
    
    int peek() {
        if (!s2.empty()) {
            return s2.top();
    }
    return front;
    }
    
    bool empty() {
         return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */