class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> st;
        for(auto i : deadends)
            st.insert(i);
        queue<string> q;
        if(st.find("0000") == st.end())
        {
            q.push("0000");
            st.insert("0000");
        }
        int count = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int x = 0; x < sz; x++)
            {
                auto s = q.front();
                q.pop();
                if(s == target)
                    return count;
                for(int i = 0; i < 4; i++)
                {
                    if(s[i] == '0')
                    {
                        s[i] = '9';
                        if(st.find(s) == st.end())
                        {
                            q.push(s);
                            st.insert(s);
                        }
                        s[i] = '1';
                        if(st.find(s) == st.end())
                        {
                            q.push(s);
                            st.insert(s);
                        }
                        s[i] = '0';
                    }
                    else if(s[i] == '9')
                    {
                        s[i] = '8';
                        if(st.find(s) == st.end())
                        {
                            q.push(s);
                            st.insert(s);
                        }
                        s[i] = '0';
                        if(st.find(s) == st.end())
                        {
                            q.push(s);
                            st.insert(s);
                        }
                        s[i] = '9';
                    }
                    else
                    {
                        s[i]--;
                        if(st.find(s) == st.end())
                        {
                            q.push(s);
                            st.insert(s);
                        }
                        s[i]++;
                        s[i]++;
                        if(st.find(s) == st.end())
                        {
                            q.push(s);
                            st.insert(s);
                        }
                        s[i]--;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};