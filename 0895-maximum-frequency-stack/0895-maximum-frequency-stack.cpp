class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>>pq;
    map<int,int>m;
    int time=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        pq.push({++m[val],{++time,val}});
    }
    
    int pop() {
        int ele=pq.top().second.second;
        pq.pop();
        m[ele]--;
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */