class Solution {
public:
    
    vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
                                      {0, 4}, {3, 5, 1}, {4, 2}};

    void dfs(string state, unordered_map<string, int>& visited, int zeroPos, int moves) 
    {
        if (visited.count(state) && visited[state] <= moves) 
            return;
        
        visited[state] = moves;

        for (int nextPos : directions[zeroPos]) 
        {
            swap(state[zeroPos], state[nextPos]);  
            dfs(state, visited, nextPos,
                moves + 1);  
            swap(state[zeroPos],
                 state[nextPos]);  
        }
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        string startState;
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 3; j++) 
                startState += to_string(board[i][j]);
        }
        
        unordered_map<string, int> visited;
        dfs(startState, visited, startState.find('0'), 0);
        return visited.count("123450") ? visited["123450"] : -1;
    }
};
    
//     vector<vector<int>> v;
//     vector<int> dx = {-1, 0, 0, 1};
//     vector<int> dy = {0, -1, 1, 0};
//     map<string, int> mp, vis; // mp working as dp
//     int sum = 100;
    
//     int dfs(int i, int j, vector<vector<int>> &board, int count)
//     {
//         if(board == v)
//         {
//             sum = min(sum, count);
//             return 0;
//         }
//         if(count >= sum || count >= 18)
//             return 100;
        
//         string s = "";
//         for(int i = 0; i < 2; i++)
//         {
//             for(int j = 0; j < 3; j++)
//                 s += to_string(board[i][j]);
//         }
//         // if(mp.find(s) != mp.end())
//         //     return mp[s];
//         // if(vis.find(s) != vis.end())
//         //     return 100;
//         // vis[s] = 1;
        
//         // if(mp.find(board) != mp.end())
//         //     return mp[board];
//         // if(vis.find(board) != vis.end())
//         //     return 100;
//         // vis[board] = 1;
        
//         auto isValid = [&](int i, int j)
//         {
//             return i >= 0 && i < 2 && j >= 0 && j < 3;
//         };
        
//         int ans = 100;
//         for(int x = 0; x < 4; x++)
//         {
//             auto nx = i + dx[x];
//             auto ny = j + dy[x];
//             if(isValid(nx, ny))
//             {  
//                 swap(board[i][j], board[nx][ny]);
//                 ans = min(ans, 1 + dfs(nx, ny, board, count+1));
//                 swap(board[i][j], board[nx][ny]);
//             }
//         }
//         // s = "";
//         // for(int i = 0; i < 2; i++)
//         // {
//         //     for(int j = 0; j < 3; j++)
//         //         s += board[i][j];
//         // }
//         // if(mp.find(s) != mp.end())
//         //     return mp[s] = min(mp[s], ans);
//         // return mp[s] = ans;
        
//         // if(mp.find(board) != mp.end())
//         //     return mp[board] = min(mp[board], ans);
//         // return mp[board] = ans;
//         return ans;
//     }
    
//     int slidingPuzzle(vector<vector<int>>& board) {
//         // v.resize(2, vector<int> (3, 0));
//         v = {{1,2,3},{4,5,0}};
//         int x = 0, y = 0;
//         for(int i = 0; i < 2; i++)
//         {
//             for(int j = 0; j < 3; j++)
//             {
//                 if(board[i][j] == 0)
//                 {
//                     x = i;
//                     y = j;
//                 }
//             }
//         }
//         int ans = dfs(x, y, board, 0); 
//         // cout << sum << endl;
//         return ans >= 100 ? -1 : ans;
//     }
// };
    
//     vector<vector<int>> v;
//     vector<int> dx = {-1, 0, 0, 1};
//     vector<int> dy = {0, -1, 1, 0};
//     map<vector<vector<int>>, int> mp, vis; // mp working as dp
//     int sum = 100;
    
//     int dfs(int i, int j, vector<vector<int>> &board, int count)
//     {
//         if(board == v)
//         {
//             sum = min(sum, count);
//             return 0;
//         }
//         if(count >= sum || count >= 18)
//             return 100;
//         // if(mp.find(board) != mp.end())
//         //     return mp[board];
//         // if(vis.find(board) != vis.end())
//         //     return 100;
//         // vis[board] = 1;
        
//         auto isValid = [&](int i, int j)
//         {
//             return i >= 0 && i < 2 && j >= 0 && j < 3;
//         };
        
//         int ans = 100;
//         for(int x = 0; x < 4; x++)
//         {
//             auto nx = i + dx[x];
//             auto ny = j + dy[x];
//             if(isValid(nx, ny))
//             {  
//                 swap(board[i][j], board[nx][ny]);
//                 ans = min(ans, 1 + dfs(nx, ny, board, count+1));
//                 swap(board[i][j], board[nx][ny]);
//             }
//         }
//         // if(mp.find(board) != mp.end())
//         //     return mp[board] = min(mp[board], ans);
//         // return mp[board] = ans;
//         return ans;
//     }
    
//     int slidingPuzzle(vector<vector<int>>& board) {
//         // v.resize(2, vector<int> (3, 0));
//         v = {{1,2,3},{4,5,0}};
//         int x = 0, y = 0;
//         for(int i = 0; i < 2; i++)
//         {
//             for(int j = 0; j < 3; j++)
//             {
//                 if(board[i][j] == 0)
//                 {
//                     x = i;
//                     y = j;
//                 }
//             }
//         }
//         int ans = dfs(x, y, board, 0); 
//         // cout << sum << endl;
//         return ans >= 100 ? -1 : ans;
//     }
// };

// Failed testcases

// [[1,2,3],[4,0,5]]
// [[1,2,3],[5,4,0]]
// [[4,1,2],[5,0,3]]
// [[3,2,4],[1,5,0]]
// [[2,5,4],[3,0,1]]
// [[5,3,2],[0,4,1]]
