class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> st;
        vector<string> ans;
        sort(folder.begin(), folder.end());
        for(auto s : folder)
        {
            string t = "";
            bool check = true;
            for(auto i : s)
            {
                if(i == '/' && st.find(t) != st.end())
                {
                    check = false;
                    break;
                }
                t += i;
            }
            if(check)
            {
                ans.push_back(s);
                st.insert(s);
            }
        }
        return ans;
    }
};