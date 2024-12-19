class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        set<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            st.insert(arr[i]);
            if(*st.rbegin() == i)
                ans++;
        }
        return ans;
    }
};