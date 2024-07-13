class Solution {
public:
    
//     Runtime: 514 ms, faster than 12.97% of C++ online submissions for Robot Collisions.
// Memory Usage: 280.7 MB, less than 12.97% of C++ online submissions for Robot Collisions.
    
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ans;
        vector<vector<int>> v;

        for(int i = 0; i < n; i++)
        {
            if(directions[i] == 'L')
                v.push_back({positions[i], healths[i], 0});
            else
                v.push_back({positions[i], healths[i], 1});
        }
        
        sort(v.begin(), v.end());
        
        // for(int i = 0; i < n; i++)
        // {
        //     for(auto j : v[i])
        //         cout << j << " ";
        //     cout << endl;
        // }
        
        stack<int> st;

        
        for(int i = 0; i < n; i++)
        {
            // if(i == 1)
            if(st.empty() || v[i][2] == 1)
            {
                st.push(i);
                continue;
            }
            

            // cout << i << "->" << endl;
            while(!st.empty() && v[st.top()][2] == 1 && v[i][2] == 0)
            {
                int x = st.top();
                auto it = v[st.top()];
                st.pop();
                if(v[i][1] > it[1])
                {
                    // cout << 1 << endl;
                    v[i][1]--;
                    // st.pop();
                }
                else if(v[i][1] < it[1])
                {
                    // cout << 2 << endl;
                    v[x][1]--;
                    st.push(x);
                    v[i][2] = -1;
                    break;
                }
                else
                {
                    // cout << 3 << endl;
                    v[i][2] = -1;
                    break;
                }
            }
            if(v[i][2] == -1)
                continue;
            st.push(i);
        }
        
        
        map<int,int> mp;
        while(!st.empty())
        {
            int x = st.top();
            auto it = v[st.top()];
            st.pop();
            
            mp[it[0]] = v[x][1];
            // st.pop();
            // ans.push_back(it[1]);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(mp.find(positions[i]) != mp.end())
            {
                ans.push_back(mp[positions[i]]);
            }
        }
        return ans;
        // reverse(ans.begin(), ans.end());
        
    }
};