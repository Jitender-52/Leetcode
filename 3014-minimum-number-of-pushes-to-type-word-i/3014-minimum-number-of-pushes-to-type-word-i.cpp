class Solution {
public:
    
    int minimumPushes(string word) {
        int n = word.length();
        map<char,int> mp;
        for(auto i : word)
            mp[i]++;
        vector<int> v;
        for(auto i : mp)
            v.push_back(i.second);
        sort(v.rbegin(), v.rend());
        int ans = 0, count = 0, x = 1;
        for(int i = 0; i < v.size(); i++)
        {
            ans += x * v[i];
            count++;
            if(count == 8)
            {
                count = 0;
                x++;
            }
        }
        return ans;
    }
};