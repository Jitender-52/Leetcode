class Solution {
public:
    
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingQueue;
        
        int targetArrival = times[targetFriend][0];
        sort(times.begin(), times.end());

        int nextChair = 0;  
        set<int> availableChairs;
        for (auto i : times) 
        {
            int arrival = i[0];
            int leave = i[1];
            while (!leavingQueue.empty() && leavingQueue.top().first <= arrival) 
            {
                availableChairs.insert(leavingQueue.top().second);
                leavingQueue.pop();
            }

            int currentChair;
            if (!availableChairs.empty()) 
            {
                currentChair = *availableChairs.begin();
                availableChairs.erase(availableChairs.begin());
            } 
            else 
                currentChair = nextChair++;
            leavingQueue.push({leave, currentChair});
            if (arrival == targetArrival) 
                return currentChair;
        }
        return 0;
    }
};
    
//     int smallestChair(vector<vector<int>>& times, int targetFriend) {
//         int n = times.size();
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; // {leavingTime, FriendNumber}
//         set<int> st;
//         for(int i = 0; i < n; i++)
//             st.insert(i);
//         sort(times.begin(), times.end());
//         int ans = 0;
//         for(int i = 0; i <= targetFriend; i++)
//         {
//             while(!pq.empty() && pq.top().first <= times[i][0])
//             {
//                 st.insert(pq.top().second);
//                 pq.pop();
//             }
//             ans = *st.begin();
//             st.erase(st.begin());
//         }
//         return ans;
//     }
// };