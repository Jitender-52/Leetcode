class Solution {
public:
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int m = people.size();
        map<int,int> mp;
        set<int> st;
        for(int i = 0; i < m; i++)
        {
            st.insert(people[i]);
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(flowers.begin(), flowers.end());
        int i = 0;
        for(auto j : st)
        {
            while(i < n && flowers[i][0] <= j)
            {
                pq.push(flowers[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top() < j)
            {
                pq.pop();
            }
            mp[j] = (int)(pq.size());
        }
        
        vector<int> ans(m);
//         for(auto i : mp)
//         {
//             cout << i.first << " " << i.second << endl;
//         }
        
        for(int i = 0; i < m; i++)
        {
            ans[i] = mp[people[i]];
        }
        return ans;
    }
};