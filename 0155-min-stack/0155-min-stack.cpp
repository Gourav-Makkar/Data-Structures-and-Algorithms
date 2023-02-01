class MinStack {
public:
    stack<long>st;
    long mn;
    MinStack() {
        
    }
    
    void push(int val) {

       if(st.empty())
       {
           st.push(val);
           mn=val;
       }
       else if(val<=mn)
       {
           st.push(2ll*val-mn);
           mn=val;
       }
        else
            st.push(val);
    }
    
    void pop() {
        if(st.empty())
            return;
        long ele=st.top();
        if(ele<mn)
        {
            mn=2ll*mn-ele;
        }
        st.pop();
    }
    
    int top() {
        if(st.empty())
            return -1;
        if(st.top()<mn)
            return mn;
        return st.top();
    }
    
    int getMin() {
        if(st.empty())
            return -1;
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */