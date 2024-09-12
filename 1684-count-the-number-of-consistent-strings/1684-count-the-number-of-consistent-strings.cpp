class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> st;
        for(auto i : allowed)
            st.insert(i);
        int ans = 0;
        for(auto i : words)
        {
            bool check = true;
            for(auto j : i)
            {
                if(st.find(j) == st.end())
                {
                    check = false;
                    break;
                }
            }
            ans += check;
        }
        return ans;
    }
};