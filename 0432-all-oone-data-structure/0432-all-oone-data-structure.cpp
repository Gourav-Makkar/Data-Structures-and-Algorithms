class AllOne {
public:
    map<string,int>m;
    set<pair<int,string>>s;
    AllOne() {
        
    }
    
    void inc(string key) {
      if(m.find(key)==m.end())
      {
          m[key]++;
          s.insert({m[key],key});
      }
      else
      {
          s.erase({m[key],key});
          m[key]++;
          s.insert({m[key],key});
      }
    }
    
    void dec(string key) {
        s.erase({m[key],key});
        m[key]--;
        if(m[key]!=0)
            s.insert({m[key],key});
        else
            m.erase(key);

    }
    
    string getMaxKey() {
        if(m.size()==0)
            return "";
        auto it=s.rbegin();
        return it->second;
    }
    
    string getMinKey() {
        if(m.size()==0)
            return "";
        auto it=s.begin();
        return it->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */