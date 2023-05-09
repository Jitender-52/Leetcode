class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &v)
    {
        int m = v.size();
        int n = v[0].size();

        int is = -1;
        int js = -1;
        int ie = m;
        int je = n;
        int check = 0;

        int i = 0;
        int j = 0;
        vector<int> ans;
        while (ans.size() != m * n)
        {
            // cout << i << " " << j << endl;
            if (check == 0)
            {
                ans.push_back(v[i][j]);
                j++;
            }
            else if (check == 1)
            {
                ans.push_back(v[i][j]);
                i++;
            }
            else if (check == 2)
            {
                ans.push_back(v[i][j]);
                j--;
            }
            else if (check == 3)
            {
                ans.push_back(v[i][j]);
                i--;
            }

            if (j == je)
            {
                j--;
                is++;
                check = 1;
                i++;
            }
            else if (i == ie)
            {
                i--;
                je--;
                check = 2;
                j--;
            }
            else if (j == js)
            {
                j++;
                ie--;
                check = 3;
                i--;
            }
            else if (i == is)
            {
                i++;
                js++;
                check = 0;
                j++;
            }
        }
        return ans;
    }
};