class Solution {
public:
    
    int minJumps(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int, vector<int>>mp;
        for (int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        
        queue<int>q;
        vector<bool>visited(n, false);
        q.push(0);
        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int currIdx = q.front();
                q.pop();
                if (currIdx == n - 1) return steps;
                //================================================================
                //EXPLORE ALL POSSIBLE OPTIONS
                if (currIdx + 1 < n && !visited[currIdx + 1])  //OPTION-1 (Move Forward)
                {
                    visited[currIdx + 1] = true;
                    q.push(currIdx + 1);
                }
                if (currIdx - 1 >= 0 && !visited[currIdx - 1]) //OPTION-2 (Move Backward)
                {
                    visited[currIdx - 1] = true;
                    q.push(currIdx - 1);
                }
                for (int newIdx : mp[arr[currIdx]])  //OPTION-3 (Move to same valued idx)
                {                                 //newIdx coud be before currIdx or after currIdx
                    if (!visited[newIdx]) 
                    {
                        visited[newIdx] = true;
                        q.push(newIdx);
                    }
                }
                //===================================================================
                mp[arr[currIdx]].clear();    //EXPLAINED BELOW :)
            }
            steps++;
        }
        return -1;
    }
};
    
    
//             int minJumps(vector<int>& arr) {
//                 int n = arr.size();
//                 map<int,vector<int>> mp;
//                 for(int i = 0; i < n; i++)
//                 {
//                     mp[arr[i]].push_back(i);
//                 }
                
//                 queue<int> q;
//                 q.push(0);
                
//                 vector<int> vis(n, 0);
//                 vis[0] = 1;
                
//                 int count = 0;
//                 while(!q.empty())
//                 {
//                     int size = q.size();
//                     for(int i = 0; i < q.size(); i++)
//                     {
//                         int temp = q.front();
//                         q.pop();
//                         if(temp == n-1)
//                         {
//                             return count;
//                         }
//                         vector<int> &v = mp[arr[temp]];
//                         v.push_back(temp-1);
//                         v.push_back(temp+1);
//                         for(auto j : v)
//                         {
//                             if(j >= 0 && j < n && !vis[j])
//                             {
//                                 vis[j] = 1;
//                                 q.push(j);
//                             }
//                         }
//                         mp[arr[temp]].clear();
//                     }
//                     count++;
//                 }
//                 return 0;
//             }
// };
    
    
    
//         int minJumps(vector<int>& arr) {
//             int n = arr.size();
//             unordered_map<int,int> mp;
//             unordered_map<int,int> mp2;
           
//             for(int i = 0; i <= n; i++)
//             {
//                 mp[i] = 1e6;
//             }
//             mp[0] = 1;
//             mp2[arr[0]] = 1;
//             mp[n] = 1e6;
//             int last = mp[n];
//             for(int j = 0; j < n; j++)
//             {
//                 for(int i = 1; i < n; i++)
//                 {
//                     mp[i] = min({mp[i], mp[i-1]+1, mp[i+1]+1});
//                     if(mp2[arr[i]] > 0)
//                         mp[i] = min(mp[i], mp2[arr[i]] + 1);
//                     if(mp2[arr[i]] == 0)
//                     {
//                         mp2[arr[i]] = mp[i];
//                     }
//                     else
//                     {
//                     mp2[arr[i]] = min({mp[i-1]+1, mp[i+1]+1, mp2[arr[i]]});
//                     }
//                     // cout << mp[i] << " " << mp2[arr[i]] << endl;
//                 }
//                 if(mp[n-1] == last)
//                     break;
//                 last = mp[n];
//             }
            
//             return mp[n-1]-1;
//         }
// };
    
    
//     int minJumps(vector<int>& arr) {
//         int n = arr.size();
        
//         map<int,int> mp;
//         mp[arr[n-1]] = 1;
//         vector<int> dp(n+1, INT_MAX);
//         dp[n-1] = 1;
//         for(int i = n-2; i >= 0; i--)
//         {
//             if(mp[arr[i]] > 0)
//             {
//                 dp[i] = min(dp[i], mp[arr[i]] + 1);
//             }
//             dp[i] = min(dp[i+1] + 1, dp[i]);
//             mp[arr[i]] = dp[i];
//         }
//         return dp[0]-1;
//     }
// };