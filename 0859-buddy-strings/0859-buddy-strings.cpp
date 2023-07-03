class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n != m)
            return false;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != goal[i])
                count++;
        }
        if(count == 0)
        {
            map<char,int> mp;
            for(int i = 0; i < n; i++)
            {
                if(mp[s[i]] == 1)
                    return true;
                mp[s[i]]++;
            }
        }
        else if(count == 2)
        {
            count = 0;
            char a, b, c, d;
            for(int i = 0; i < n; i++)
            {
                if(count == 0 && s[i] != goal[i])
                {
                    a = s[i];
                    b = goal[i];
                    count++; // forgot to count++;
                }
                else if(s[i] != goal[i])
                {
                    if(a == goal[i] && b == s[i])
                        return true;
                }
                // forgot to check s[i] != goal[i] in both conditions
                // cout << a << " " << b << endl;
            }
        }
        return false;
    }
};