class CustomStack {
public:
    vector<pair<int,int>>v;
    int n;
    CustomStack(int maxSize) {
       n=maxSize;
    }
    
    void push(int x) {
        if(v.size()!=n)
        {
            v.push_back({x,0});
        }
    }
    
    int pop() {
        if(v.size()==0)
            return -1;
        pair<int,int>p=v.back();
        v.pop_back();
        
        if(v.size()!=0)
            (v.back()).second+=p.second;
        
        return p.first+p.second;
    }
    
    void increment(int k, int val) {
        if(v.size()==0)
            return;
        int idx=min((int)(v.size()-1),k-1);
        v[idx].second+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */