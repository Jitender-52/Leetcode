class MyCalendar {
public:
    
//     Runtime: 87 ms, faster than 45.85% of C++ online submissions for My Calendar I.
// Memory Usage: 41.7 MB, less than 73.44% of C++ online submissions for My Calendar I.
    
    vector<pair<int, int>> v;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i = 0; i < v.size(); i++)
        {
            if((start >= v[i].first && start < v[i].second) || (end > v[i].first && end < v[i].second) || (start < v[i].first && end >= v[i].second))
            {
                return false;
            }
        }
        v.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */