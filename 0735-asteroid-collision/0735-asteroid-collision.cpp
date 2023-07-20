class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(auto i : asteroids)
        {
            if(st.empty() || st.top() < 0)
            {
                st.push(i);
                continue;
            }
            if(i >= 0)
            {
                st.push(i);
                continue;
            }
            
            bool check = true;
            while(!st.empty() && st.top() >= 0)
            {
                if(st.top() >= abs(i))
                {
                    if(st.top() == abs(i))
                        st.pop();
                    check = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(check)
                st.push(i);
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};