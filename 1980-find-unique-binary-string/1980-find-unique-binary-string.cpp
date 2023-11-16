class Solution {
public:
    
    int n;
    set<string> st;
    string ans;
    
    void find(int i, string &s)
    {
        if(i == n)
        {
            if(st.find(s) == st.end())
                ans = s;
            return;
        }
        s += '0';
        find(i+1, s);
        s.pop_back();
        s += '1';
        find(i+1, s);
        s.pop_back();
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums[0].size();
        for(auto i : nums)
            st.insert(i);
        string s = "";
        find(0, s);
        return ans;
    }
};