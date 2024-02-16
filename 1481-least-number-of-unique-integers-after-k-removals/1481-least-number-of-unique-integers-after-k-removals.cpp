class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto i : arr)
            mp[i]++;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(auto i : mp)
        {
            pq.push({i.second, i.first});
        }
        while(!pq.empty() && k--)
        {
            int a = pq.top()[0];
            int b = pq.top()[1];
            pq.pop();
            a--;
            if(a != 0)
                pq.push({a, b});
        }
        return pq.size();        
    }
};