class AllOne {
public:
    
    unordered_map<string, int> mp;
    set<pair<int, string>> st;
    
    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
        int n = mp[key];
        st.insert({n, key});
        st.erase({n-1, key});
    }
    
    void dec(string key) {
        int n = mp[key];
        mp[key]--;
        if(mp[key] == 0)
            mp.erase(key);
        else
            st.insert({n-1, key});
        st.erase({n, key});
    }
    
    string getMaxKey() {
        if(st.size())
            return st.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if(st.size())
            return (*st.begin()).second;
        return "";
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