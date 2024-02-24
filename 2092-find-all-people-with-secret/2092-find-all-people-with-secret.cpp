class Solution {
public:
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i : meetings)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        // queue<pair<int,int>> q;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // queue will not work because we need to sort according to the smaller time to meet first so that then bigger time meets can also get the secret;
        vector<int> vis(n), ans;
        vis[0] = 1;
        vis[firstPerson] = 1;
        pq.push({0, 0});
        // q.push({firstPerson, 0});
        pq.push({0, firstPerson});
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            // ans.push_back(p.second); // same person can be repeated again and again
            vis[p.second] = 1;
            for(auto i : adj[p.second])
            {
                // if(i.first == 4 && p.second == 5)
                // {
                //     cout << i.second << " " << p.first << endl;
                //     cout << "HII" << endl;
                // }
                if(!vis[i.first] && i.second >= p.first)
                {
                    // vis[i.first] = 1; // this will not allow to get the bigger time from the smaller time meets
                    pq.push({i.second, i.first});
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};
    
//     vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//         vector<vector<pair<int,int>>> adj(n);
//         for(auto i : meetings)
//         {
//             adj[i[0]].push_back({i[1], i[2]});
//             adj[i[1]].push_back({i[0], i[2]});
//         }
//         queue<pair<int,int>> q;
//         vector<int> vis(n), ans;
//         vis[0] = 1;
//         vis[firstPerson] = 1;
//         q.push({0, 0});
//         q.push({firstPerson, 0});
//         while(!q.empty())
//         {
//             auto p = q.front();
//             q.pop();
//             ans.push_back(p.first);
//             for(auto i : adj[p.first])
//             {
//                 if(i.first == 4 && p.first == 5)
//                 {
//                     cout << i.second << " " << p.second << endl;
//                     cout << "HII" << endl;
//                 }
//                 if(!vis[i.first] && i.second >= p.second)
//                 {
//                     vis[i.first] = 1;
//                     q.push({i.first, i.second});
//                 }
//             }
//         }
//         return ans;
//     }
// };
    
//     vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//         sort(meetings.begin(), meetings.end(), [&](vector<int> &a, vector<int> &b){
//            return a[2] < b[2]; 
//         });
//         vector<int> ans, vis(n, 0);
//         vis[firstPerson] = 1;
//         vis[0] = 1;
//         ans.push_back(0);
//         ans.push_back(firstPerson);
//         for(auto i : meetings)
//         {
//             if(vis[i[0]] && !vis[i[1]])
//             {
//                 vis[i[1]] = 1;
//                 ans.push_back(i[1]);
//             }
//             if(vis[i[1]] && !vis[i[0]])
//             {
//                 vis[i[0]] = 1;
//                 ans.push_back(i[0]);
//             }
//         }
//         return ans;
//     }
// };