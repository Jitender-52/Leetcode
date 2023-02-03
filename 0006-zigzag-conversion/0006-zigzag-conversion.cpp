class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();

        if(numRows == 1)
            return s;
        
        int sections = ceil(n / (2.0 * (numRows - 1)));
        int col = sections * (numRows-1);
        
        //  int sections = ceil(n / (2 * numRows - 2.0));
        // int col = sections * (numRows - 1);
        
        vector<vector<char>> v(numRows, vector<char>(col, ' '));
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n)
        {
            if(k == 0)
            {
                for(; k < numRows && i < n; k++, i++)
                {
                    v[k][j] = s[i];
                }
                k -= 2;
                j++;
            }
            else
            {
                v[k][j] =  s[i];
                i++;
                k--;
                j++;
            }
        }
        
        string ans = "";
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(v[i][j] != ' ')
                    ans += v[i][j];
            }
        }
        return ans;
    }
};