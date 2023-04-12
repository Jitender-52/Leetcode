class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
    string help = "";
    string d = "..";
    string e = ".";

    for (int i = 1; i < s.length(); i++)
    {

        if (s[i] == '/' || i == s.length()- 1)
        {
             if(s[i] != '/')
            {
                help += s[i];
            }
            // cout << "Help = " << help << endl;
            // if (help == d)
            if (help == "..")
            {
                // cout << "HII" << endl;
                if (!st.empty())
                {
                    st.pop();
                }
                help = "";
            }
            else if (help == ".")
            {
                help = "";
            }
            else
            {
                if(help.size() > 0)
                st.push(help);
                help = "";
            }
        }
        else
        {
            help += s[i];
        }
    }
    if (help.size() > 0)
    {
        st.push(help);
    }
    string ans = "";
    if (st.empty())
    {
        ans += "/";
    }
    while (!st.empty())
    {
        help = st.top();
        for (int i = help.length() - 1; i >= 0; i--)
        {
            if (help[i] == '/' && help[i + 1] == '/' && i < help.length() - 1)
            {
                continue;
            }
            else
            {
                ans += help[i];
            }
        }
        ans += "/";
        st.pop();
    }
    string last = "";
    for(int i= ans.length() -1; i>= 0; i--)
    {
        last += ans[i];
    }
    return last;
    }
};