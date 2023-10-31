class Solution {
public:
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
                if(a - 1 > 0)
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