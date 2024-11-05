class Solution {
public:
    int minChanges(string s) {
        int n = s.length(), ans = 0;
        for(int i = 0; i < n; i++)
        {
            char a = s[i];
            int count = 0;
            while(i < n && s[i] == a)
            {
                count++;
                i++;
            }
            if(count % 2 == 1)
                ans++;
            else
                i--;
        }
        return ans;
    }
};