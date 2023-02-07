class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        map<int,int> mp;
        
        int ans = 0;
        int s = 0;
        for(int i = 0; i < n; i++)
        {
            mp[fruits[i]]++;
            while(mp.size() > 2)
            {
                mp[fruits[s]]--;
                if(mp[fruits[s]] == 0)
                {
                    mp.erase(fruits[s]);
                }
                s++;
            }
            ans = max(ans, i - s + 1);
        }
        return ans;
    }
};