class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ans = 1;
        set<int> st;
        for(auto i : rolls)
        {
            st.insert(i);
            if(st.size() == k)
            {
                ans++;
                st.clear();
            }
        }
        return ans;
    }
};