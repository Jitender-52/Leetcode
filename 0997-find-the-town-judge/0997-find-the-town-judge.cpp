class Solution {
public:
    
    int findJudge(int m, vector<vector<int>>& trust) {
        
        int n = trust.size();
        map<int,int> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp[trust[i][0]]++;
        }
        
        int a = 0;
        int count = 0;
        for(int i = 0; i < m; i++)
        {
            if(mp[i+1] == 0)
            {
                a = i+1;
                count++;
            }
        }
        
        if(count != 1)
            return -1;
        
        mp.clear();
        
        for(int i = 0; i < n; i++)
        {
            if(trust[i][1] == a)
                mp[trust[i][0]]++;
        }
        
        if(mp.size() == m-1)
            return a;
        return -1;
    }
};