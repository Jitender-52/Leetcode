class Solution {
public:
    
//     Runtime: 448 ms, faster than 10.68% of C++ online submissions for Maximum Number of Integers to Choose From a Range I.
// Memory Usage: 227.3 MB, less than 6.94% of C++ online submissions for Maximum Number of Integers to Choose From a Range I.
    
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m = banned.size();
        long long sum = 0;
        for(int i = 0; i < m; i++)
        {
            if(banned[i] <= n)
            {
                sum += banned[i];
            }
        }
        
        map<int,int> mp;
        for(auto i : banned)
        {
            mp[i]++;
        }
        
        vector<int> v;
        for(int i = 1; i <= n; i++)
        {
            if(mp[i] == 0)
                v.push_back(i);
        }
        
        sort(v.begin(), v.end());
        
        int i = 0;
        int count = 0;
        
        sum = 0;
        while(i < v.size() && sum < maxSum)
        {
            sum += v[i];
            if(sum > maxSum)
                break;
            count++;
            i++;
        }
        return count;
    }
};