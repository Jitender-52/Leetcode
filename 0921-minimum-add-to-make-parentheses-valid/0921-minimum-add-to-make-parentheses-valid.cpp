class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        set<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(st.find(i) == st.end())
            {
                bool check = false;
                if(s[i] == '(')
                {
                    for(int j = i+1; j < n; j++)
                    {
                        if(s[j] == ')' && st.find(j) == st.end())
                        {
                            st.insert(j);
                            check = true;
                            break;
                        }
                    }
                }
                if(!check)
                    ans++;
            }
        }
        return ans;
    }
};