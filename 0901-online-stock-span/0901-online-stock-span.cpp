class StockSpanner {
public:
    stack<int>st;
    unordered_map<int,int>m;
    bool flag=true;
    int i=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(flag)
        {
            m[price]=i;
            i++;
            st.push(price);
            flag=false;
            return 1;
        }
       m[price]=i;
       while(!st.empty() && st.top()<=price)
       {
           st.pop();
       }
        
       int idx=(st.empty())?-1:m[st.top()];
       st.push(price);
       int ans=i-idx;
       i++;
       return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */