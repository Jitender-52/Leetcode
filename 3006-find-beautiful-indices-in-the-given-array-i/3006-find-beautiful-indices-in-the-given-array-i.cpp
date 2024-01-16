class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        int p = a.length(), q = b.length();
        vector<int> v1, v2;
        for(int i = 0; i < n; i++)
        {
            if(i + p <= n && s.substr(i, p) == a)
                v1.push_back(i);
            if(i + q <= n && s.substr(i, q) == b)
                v2.push_back(i);
        }
        int i = 0, j = 0;
        vector<int> ans;
        while(i < v1.size() && j < v2.size())
        {
            if(abs(v1[i] - v2[j]) <= k)
            {
                ans.push_back(v1[i]);
                i++;
            }
            else if(v1[i] <= v2[j])
                i++;
            else
                j++;
        }
        return ans;
    }
};