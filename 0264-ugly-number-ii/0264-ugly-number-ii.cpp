class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        pq.push(1);
        int i = 1;
        // vector<int> vis(1e6, 0);
        map<long long,int> vis;
        while(1)
        {
            int x = pq.top();
            // cout << x << " ";
            if(i == n)
                return x;
            pq.pop();
            vector<int> v = {2, 3, 5};
            i++;
            if(pq.size() > n)
                continue;
            for(int i = 0; i < 3; i++)
            {
                if(!vis[v[i] * 1LL * x])
                {
                    pq.push(v[i] * 1LL * x);
                    vis[v[i] * 1LL * x] = 1;
                }
            }
        }
        return -1;
    }
};