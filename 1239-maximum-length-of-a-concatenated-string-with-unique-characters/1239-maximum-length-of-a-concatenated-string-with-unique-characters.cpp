class Solution {
public:
    
    // Why its not working??
    
//     int ans = 0;
    
//     void maximum(int i, string &s, vector<string> &arr, vector<int> &v)
//     {
//         int n = arr.size();
//         if(i >= n)
//             return;
//         string x = s + arr[i];
//         maximum(i+1, s, arr, v);
//         for(auto j : arr[i])
//         {
//             if(v[j - 'a'] > 0)
//                 return;
//         }
//         for(auto j : arr[i])
//             v[j - 'a']++;
//         ans = max(ans, (int)s.length());
//         maximum(i+1, x, arr, v);
//         for(auto j : arr[i])
//             v[j - 'a']--;
//     }
    
//     int maxLength(vector<string>& arr) {
//         string s = "";
//         vector<int> v(26, 0);
//         maximum(0, s, arr, v);
//         return ans;
//     }
// };
    
    
//     Runtime: 57 ms, faster than 53.46% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
// Memory Usage: 94.7 MB, less than 24.62% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
    
// Time Complexity - (2 ^ n) * m,  where n = arr.size() and m = arr[i].length();
//     Inside every recursive call there is time complexity of s.size();
// Auxillary Space - 2 ^ n
    
    int ans = 0;
    
    void maximum(int i, string &s, vector<string> &arr)
    {
        int n = arr.size();
        vector<int> v(26);
        for(auto it : s)
            v[it - 'a']++;
        for(auto it : v)
        {
            if(it > 1)
                return;
        }
        ans = max(ans, (int)s.length());
        if(i >= n)
            return;
        string x = s + arr[i];
        maximum(i+1, s, arr);
        maximum(i+1, x, arr);
    }
    
    int maxLength(vector<string>& arr) {
        string s = "";
        maximum(0, s, arr);
        return ans;
    }
};