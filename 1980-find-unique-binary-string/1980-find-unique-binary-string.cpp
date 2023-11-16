class Solution {
public:
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            ans += nums[i][i] == '0' ? '1' : '0';
        }
        return ans;
    }
};
    
//     Runtime: 371 ms, faster than 16.92% of C++ online submissions for Find Unique Binary String.
// Memory Usage: 10.8 MB, less than 43.66% of C++ online submissions for Find Unique Binary String.
    
//     int n;
//     set<string> st;
//     string ans;
    
//     void find(int i, string &s)
//     {
//         if(i == n)
//         {
//             if(st.find(s) == st.end())
//                 ans = s;
//             return;
//         }
//         s += '0';
//         find(i+1, s);
//         s.pop_back();
//         s += '1';
//         find(i+1, s);
//         s.pop_back();
//     }
    
//     string findDifferentBinaryString(vector<string>& nums) {
//         n = nums[0].size();
//         for(auto i : nums)
//             st.insert(i);
//         string s = "";
//         find(0, s);
//         return ans;
//     }
// };