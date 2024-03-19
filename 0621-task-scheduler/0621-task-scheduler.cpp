class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        for(auto i : tasks)
            mp[i]++;
        
        priority_queue<pair<int,char>, vector<pair<int,char>>> pq, pq1;
        
        for(auto i : mp)
            pq.push({i.second, i.first});
        for(auto i : mp)
            mp[i.first] = -1e9;
        
        int time = 0;
        while(pq.size())
        {
            priority_queue<pair<int,char>, vector<pair<int,char>>> pq1;
            bool check = false;
            auto it = pq.top();
            while(!check && pq.size())
            {
                it = pq.top();
                pq.pop();
                if(time - mp[it.second] > n)
                {
                    check = true;
                    break;
                }
                pq1.push(it);
            }
            if(check)
            {
                if(it.first > 1)
                    pq.push({it.first-1, it.second});
                mp[it.second] = time;
            }
            while(!pq1.empty())
            {
                pq.push(pq1.top());
                pq1.pop();
            }
            time++;
        }
        return time;
    }
};