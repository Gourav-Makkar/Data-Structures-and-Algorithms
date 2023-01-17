class CustomStack {
public:
    vector<int>v;
    int n;
    CustomStack(int maxSize) {
       n=maxSize;
    }
    
    void push(int x) {
        if(v.size()!=n)
        {
            v.push_back(x);
        }
    }
    
    int pop() {
        if(v.size()==0)
            return -1;
        int ele=v.back();
        v.pop_back();
        return ele;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,(int)v.size());i++)
            v[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */