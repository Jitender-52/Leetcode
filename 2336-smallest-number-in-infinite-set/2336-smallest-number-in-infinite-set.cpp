class SmallestInfiniteSet {
public:
    
//     Runtime: 132 ms, faster than 24.45% of C++ online submissions for Smallest Number in Infinite Set.
// Memory Usage: 46.3 MB, less than 14.20% of C++ online submissions for Smallest Number in Infinite Set.
    
    set<int> st;
    
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++)
        {
            st.insert(i);
        }
    }
    
    int popSmallest() {
        int top = *st.begin();
        st.erase(st.begin());
        return top;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */