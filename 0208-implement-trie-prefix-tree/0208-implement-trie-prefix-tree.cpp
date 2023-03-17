class Trie {
public:
    
    set<string> st;
    
    Trie() {
        
    }
    
    void insert(string word) {
        st.insert(word);
    }
    
    bool search(string word) {
        if(st.find(word) != st.end())
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        for(auto i : st)
        {
            string s = i;
            if(s.length() >= prefix.length())
            {
                string x = s.substr(0, prefix.length());
                if(x == prefix)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */