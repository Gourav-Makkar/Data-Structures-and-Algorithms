class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++){
            st.insert(i);
        }
    }
    
    int popSmallest() {
        auto it = st.begin();
        int ans = *it;
        st.erase(it);
        return ans;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};