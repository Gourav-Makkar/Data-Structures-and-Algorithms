class RandomizedCollection {
public:
    unordered_map<int,int>m;
    vector<int>v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end())
        {
            m[val]++;
            v.push_back(val);
            return true;
        }
        else
        {
            m[val]++;
            v.push_back(val);
            return false;
        }
    }
    
    bool remove(int val) {
        
        if(m.find(val)!=m.end())
        {
            m[val]--;
            if(m[val]==0)
                m.erase(val);
            auto it=find(v.begin(),v.end(),val);
            v.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */