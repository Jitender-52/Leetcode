class Solution {
public:
    
//     Runtime: 230 ms, faster than 84.69% of C++ online submissions for Sum of Beauty of All Substrings.
// Memory Usage: 36.6 MB, less than 7.77% of C++ online submissions for Sum of Beauty of All Substrings.
    
    int beautySum(string s) {
        int n = s.length(), ans = 0;
        for(int i = 0; i < n; i++)
        {
            vector<int> v(26);
            // int maxi = 0, mini = 1000;
            map<int, int> mp;
            for(int j = i; j < n; j++)
            {
                v[s[j] - 'a']++;
                int a = v[s[j] - 'a'];
                // if(a - 1 > 0) // it's is better than down condition. Accepted with it
                if(mp.find(a-1) != mp.end()) // just for checking 
                {
                    mp[a-1]--;
                    if(mp[a-1] == 0)
                        mp.erase(a-1);
                }
                mp[a]++;
                int x = mp.begin()->first;
                int y = mp.rbegin()->first;
                ans += y - x;
            }
        }
        return ans;
    }
};