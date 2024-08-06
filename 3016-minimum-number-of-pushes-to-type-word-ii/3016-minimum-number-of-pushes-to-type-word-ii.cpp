class Solution {
public:
    
//     Runtime: 196 ms, faster than 9.82% of C++ online submissions for Minimum Number of Pushes to Type Word II.
// Memory Usage: 29 MB, less than 9.45% of C++ online submissions for Minimum Number of Pushes to Type Word II.
    
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

// "alporfmdqsbhncwyu"
//     8 8 1
    
    
    