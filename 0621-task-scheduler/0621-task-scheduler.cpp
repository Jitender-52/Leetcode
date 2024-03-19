class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26);
        int maxi = 0;
        for(auto i : tasks)
        {
            v[i - 'A']++;
            maxi = max(maxi, v[i - 'A']);
        }
        int time = (maxi - 1) * (n + 1); // there will be n gaps and one of the character so total time(gaps) is (n + 1) && maxi character will take these gaps maxi-1 times as between x characters x-1 gaps will be there and the time of the starting gap will be counted in the down loop of i == maxi; 
        for(auto i : v)
        {
            if(i == maxi)
                time++;
        }
        return max(time, (int)tasks.size());
    }
};
    
//     Runtime: 2857 ms, faster than 5.04% of C++ online submissions for Task Scheduler.
// Memory Usage: 458.3 MB, less than 5.93% of C++ online submissions for Task Scheduler.
    
//     int leastInterval(vector<char>& tasks, int n) {
//         map<char,int> mp;
//         for(auto i : tasks)
//             mp[i]++;
        
//         priority_queue<pair<int,char>, vector<pair<int,char>>> pq, pq1;
        
//         for(auto i : mp)
//             pq.push({i.second, i.first});
//         for(auto i : mp)
//             mp[i.first] = -1e9;
        
//         int time = 0;
//         while(pq.size())
//         {
//             priority_queue<pair<int,char>, vector<pair<int,char>>> pq1;
//             bool check = false;
//             auto it = pq.top();
//             while(!check && pq.size())
//             {
//                 it = pq.top();
//                 pq.pop();
//                 if(time - mp[it.second] > n)
//                 {
//                     check = true;
//                     break;
//                 }
//                 pq1.push(it);
//             }
//             if(check)
//             {
//                 if(it.first > 1)
//                     pq.push({it.first-1, it.second});
//                 mp[it.second] = time;
//             }
//             while(!pq1.empty())
//             {
//                 pq.push(pq1.top());
//                 pq1.pop();
//             }
//             time++;
//         }
//         return time;
//     }
// };