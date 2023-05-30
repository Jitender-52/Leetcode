class MyHashSet {
public:
    
//     Runtime: 120 ms, faster than 42.72% of C++ online submissions for Design HashSet.
// Memory Usage: 184.2 MB, less than 18.98% of C++ online submissions for Design HashSet.
    
    vector<int> v;
    
    MyHashSet() {
        v.resize(1000001);
    }
    
    void add(int key) {
        v[key] = 1;
    }
    
    void remove(int key) {
        v[key] = 0;
    }
    
    bool contains(int key) {
        return v[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */