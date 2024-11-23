class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char> (n, '.'));
        
        for(int i = 0; i < n; i++)
        {
            int j = 0;
            while(j < m)
            {
                int count = 0;
                for(j; j < m; j++)
                {
                    if(box[i][j] == '#')
                        count++;
                    else if(box[i][j] == '*')
                    {
                        ans[j][n-i-1] = '*';
                        break;
                    }
                }
                int x = j;
                while(count > 0)
                {
                    x--; 
                    ans[x][n-i-1] = '#';
                    count--;
                }
                j++;
            }
        }
        return ans;
    }
}; 