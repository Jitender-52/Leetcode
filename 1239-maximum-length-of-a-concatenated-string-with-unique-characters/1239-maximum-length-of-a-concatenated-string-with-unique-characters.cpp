class Solution {
public:
    
    int ans = 0;
    
    void maximum(int i, string &s, vector<string> &arr)
    {
        int n = arr.size();
        vector<int> v(26);
        for(auto it : s)
            v[it - 'a']++;
        for(auto it : v)
        {
            if(it > 1)
                return;
        }
        ans = max(ans, (int)s.length());
        if(i >= n)
            return;
        string x = s + arr[i];
        maximum(i+1, s, arr);
        maximum(i+1, x, arr);
    }
    
    int maxLength(vector<string>& arr) {
        string s = "";
        maximum(0, s, arr);
        return ans;
    }
};