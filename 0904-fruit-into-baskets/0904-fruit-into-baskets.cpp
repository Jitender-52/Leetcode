class Solution {
public:
    
//     Runtime: 218 ms, faster than 30.67% of C++ online submissions for Fruit Into Baskets.
// Memory Usage: 75.3 MB, less than 13.09% of C++ online submissions for Fruit Into Baskets.
    
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;
        
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