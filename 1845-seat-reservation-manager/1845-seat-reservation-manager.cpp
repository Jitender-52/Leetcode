class SeatManager {
public:
   
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for(int i = 1; i <= n; i++)
            pq.push(i);
    }
    
    int reserve() {
        int ans = pq.top();
        pq.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
    
//     Runtime: 469 ms, faster than 15.78% of C++ online submissions for Seat Reservation Manager.
// Memory Usage: 190.8 MB, less than 12.34% of C++ online submissions for Seat Reservation Manager.
    
//     set<int> st;
//     SeatManager(int n) {
//         for(int i = 1; i <= n; i++)
//             st.insert(i);
//     }
    
//     int reserve() {
//         int ans = *st.begin();
//         st.erase(st.begin());
//         return ans;
//     }
    
//     void unreserve(int seatNumber) {
//         st.insert(seatNumber);
//     }
// };

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */