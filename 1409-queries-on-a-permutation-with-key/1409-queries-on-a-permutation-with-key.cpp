class Solution {
public:
     vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans;
        vector<int> p(m);
        for(int i = 1; i <= m; i++)
            p[i-1] = i;
         
        int n = queries.size();
        for(int i = 0; i < n; i++)
        {
            int temp = queries[i];
            int j;
            for(j = 0;j < m; j++)
            {
                if(temp==p[j])
                    break;
            }
            ans.push_back(j);
            while(j!=0)
            {
                p[j] = p[j-1];
                j--;
            }
            p[0] = temp;
        }
        return ans;
    }
};