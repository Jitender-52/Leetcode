class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> st;
        for(auto i : nums1)
            st.insert(i);
        for(auto i : nums2)
        {
            if(st.find(i) != st.end())
            {
                st.erase(i);
                ans.push_back(i);
            }
        }
        return ans;
    }
};