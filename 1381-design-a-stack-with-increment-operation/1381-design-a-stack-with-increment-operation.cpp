class CustomStack {
public:
    
    vector<int> v;
    int idx;
    
    CustomStack(int maxSize) {
        v.resize(maxSize);
        idx = -1;
    }
    
    void push(int x) {
        if(idx < (int)(v.size()) - 1)
        {
            idx++;
            v[idx] = x;
        }
    }
    
    int pop() {
        if(idx >= 0)
        {
            int ans = v[idx];
            idx--;
            return ans;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int a = min(k, idx+1);
        for(int i = 0; i < a; i++)
            v[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */