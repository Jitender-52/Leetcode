class Solution {
public:
    
//     Runtime: 2 ms, faster than 65.84% of C++ online submissions for Unique Number of Occurrences.
// Memory Usage: 8.8 MB, less than 20.45% of C++ online submissions for Unique Number of Occurrences.
    
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto i : arr)
            mp[i]++;
        set<int> st;
        for(auto i : mp)
        {
            if(st.find(i.second) != st.end())
                return false;
            st.insert(i.second);
        }
        return true;
    }
};