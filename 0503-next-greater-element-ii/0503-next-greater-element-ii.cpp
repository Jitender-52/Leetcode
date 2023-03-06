class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        // map<int,int> mp;
        vector<int> mp(n, -1);
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && nums[i] > nums[st.top()])
            {
                mp[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && nums[i] > nums[st.top()])
            {
                mp[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        
        return mp;
        
        // while(!st.empty())
        // {
        //     mp[st.top()] = -1;
        //     st.pop();
        // }
    
        
    }
};