class MyCalendarTwo {
public:
    
//     Runtime: 165 ms, faster than 34.10% of C++ online submissions for My Calendar II.
// Memory Usage: 42.6 MB, less than 71.64% of C++ online submissions for My Calendar II.
    
    map<int, int> eventCount;

    MyCalendarTwo() {
        
    }

    bool book(int start, int end) {
        eventCount[start]++;
        eventCount[end]--;

        int ongoingEvents = 0;
        for (auto &[time, change] : eventCount) 
        {
            ongoingEvents += change;
            if (ongoingEvents >= 3) 
            {
                eventCount[start]--;
                eventCount[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */