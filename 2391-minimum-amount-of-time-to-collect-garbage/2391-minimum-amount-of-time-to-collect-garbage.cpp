class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g = -1;
        int m = -1;
        int p = -1;
        int n = garbage.size();
        for(int i = 0; i < n; i++)
        {
            for(int j= 0; j < garbage[i].length(); j++)
            {
                if(garbage[i][j] == 'P')
                {
                    p = i;
                }
                if(garbage[i][j] == 'G')
                {
                    g = i;
                }
                if(garbage[i][j] == 'M')
                {
                    m = i;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i <= g; i++)
        {
            int count = 0;
            for(int j = 0; j < garbage[i].length(); j++)
            {
                if(garbage[i][j] == 'G')
                {
                    count++;
                }
            }
            ans += count;
            if(i > 0)
            {
                ans += travel[i-1];
            }
        }
        
        for(int i = 0; i <= m; i++)
        {
            int count = 0;
            for(int j = 0; j < garbage[i].length(); j++)
            {
                if(garbage[i][j] == 'M')
                {
                    count++;
                }
            }
            ans += count;
            if(i > 0)
            {
                ans += travel[i-1];
            }
        }
        
        for(int i = 0; i <= p; i++)
        {
            int count = 0;
            for(int j = 0; j < garbage[i].length(); j++)
            {
                if(garbage[i][j] == 'P')
                {
                    count++;
                }
            }
            ans += count;
            if(i > 0)
            {
                ans += travel[i-1];
            }
        }
        return ans;
    }
};