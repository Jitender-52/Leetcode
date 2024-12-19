class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Max Chunks To Make Sorted.
// Memory Usage: 9.4 MB, less than 7.32% of C++ online submissions for Max Chunks To Make Sorted.
    
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