class Solution {
public:
    
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        stack<int> st;
        st.push(0);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(target[i] >= st.top())
            {
                ans += target[i] - st.top();
            }
            st.pop();
            st.push(target[i]);
        }
        return ans;
    }
};
    
//     Runtime: 143 ms, faster than 30.63% of C++ online submissions for Minimum Number of Increments on Subarrays to Form a Target Array.
// Memory Usage: 73.1 MB, less than 66.49% of C++ online submissions for Minimum Number of Increments on Subarrays to Form a Target Array.
    
//         int minNumberOperations(vector<int>& target) {
//             int n = target.size();
//             int ans = target[0];
//             for(int i = 1; i < n; i++)
//             {
//                 ans += max(0, target[i] - target[i-1]);
//             }
//             return ans;
//         }
// };
    
    
//     int minNumberOperations(vector<int>& target) {
//         int n = target.size();
//         stack<int> st;
//         int ans = 0;
//         for(int i = 0; i < n; i++)
//         {
//             int maxi = 0;
//             while(!st.empty() && st.top() <= target[i])
//             {
//                 st.pop();
//             }
            
//             st.push(target[i]);
//         }
//     }
// };