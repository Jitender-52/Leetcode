class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int a = (i-1) % n, b = i % n, c = (i+1) % n;
            if(colors[a] != colors[b] && colors[b] != colors[c])
                ans++;
        }
        return ans;
    }
};