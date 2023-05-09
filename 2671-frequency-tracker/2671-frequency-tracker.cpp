class FrequencyTracker {
public:
    
    vector<int> v, f;
    
    FrequencyTracker() {
        v.resize(100001, 0);
        f.resize(100001, 0);
    }
    
    void add(int number) {
        f[v[number]]--;
        v[number]++;
        f[v[number]]++;
    }
    
    void deleteOne(int number) {
        if(v[number] <= 0)
            return;
        f[v[number]]--;
        v[number]--;
        f[v[number]]++;
    }
    
    bool hasFrequency(int frequency) {
        return f[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */