class Solution {
public:
    
//     Runtime: 102 ms, faster than 5.40% of C++ online submissions for Divide Players Into Teams of Equal Skill.
// Memory Usage: 57.1 MB, less than 16.20% of C++ online submissions for Divide Players Into Teams of Equal Skill.
    
    long long dividePlayers(vector<int>& v) {
        int n = v.size();
        map<int,int>mp;
        
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            mp[v[i]]++;
            sum += v[i];
        }
        
        if(sum % (n/2) != 0)
            return -1;
        
        int a = sum / (n/2);
        
        long long ans = 0;
        for(int i= 0; i < n; i++)
        {
            if(mp[v[i]] > 0)
            {
                if(mp[a - v[i]] > 0)
                    ans += v[i] * (a - v[i]);
                else
                    return -1;
                mp[v[i]]--;
                mp[a - v[i]]--;
            }
        }
        return ans;
    }
};