class Solution {
public:
    
    void dfs(string s,  map<string, priority_queue<string, vector<string>, greater<string>> > &mp, vector<string> &ans)
    {
        // ans.push_back(s);
        
        auto &pq = mp[s];
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            dfs(it, mp, ans);
        }
        
        // for(auto i : mp[s])
        // {
        //     auto x = i;
        //     mp[s].erase(x);
        //     dfs(i, mp, ans);
        // }
        
        // auto it = mp[s].begin();
        // while(it != mp[s].end())
        // {
        //     auto p = it;
        //     auto x = *it;
        //     it++;
        //     mp[s].erase(p);
        //     dfs(x, mp, ans);
        // }
        
        ans.push_back(s);
        // string x = *mp[s].begin();
        // mp[s].erase(x);
        // dfs(x, mp, ans);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>> > mp;
        for(auto v : tickets)
        {
            // mp[v[0]].insert(v[1]);
            mp[v[0]].push(v[1]);
        }
        // string s = tickets[0][0];
        // for(auto i : mp["JFK"])
        // {
        //     s = min(s, i);
        // }
        
        vector<string> ans;
        dfs("JFK", mp, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
    
//     void dfs(string s, map<string, set<string>> &mp, vector<string> &ans)
//     {
//         // ans.push_back(s);
//         if(mp[s].size() == 0)
//             return;
        
//         // for(auto i : mp[s])
//         // {
//         //     auto x = i;
//         //     mp[s].erase(x);
//         //     dfs(i, mp, ans);
//         // }
        
//         auto it = mp[s].begin();
//         while(it != mp[s].end())
//         {
//             auto p = it;
//             auto x = *it;
//             it++;
//             mp[s].erase(p);
//             dfs(x, mp, ans);
//         }
        
//         ans.push_back(s);
//         // string x = *mp[s].begin();
//         // mp[s].erase(x);
//         // dfs(x, mp, ans);
//     }
    
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         map<string, set<string>> mp;
//         for(auto v : tickets)
//         {
//             mp[v[0]].insert(v[1]);
//         }
//         string s = tickets[0][0];
//         for(auto i : mp["JFK"])
//         {
//             s = min(s, i);
//         }
        
//         vector<string> ans;
//         dfs("JFK", mp, ans);
        
//         return ans;
//     }
// };