class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses, vector<int> (numCourses, 0));
        
        for(auto i : prerequisites)
        {
            graph[i[0]][i[1]] = 1;
        }
        
        int n = numCourses;
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(graph[i][k] == 1 && graph[k][j] == 1)
                        graph[i][j] = 1;
                }
            }
        }
        
        vector<bool> ans;
        for(auto q : queries)
        {
            if(graph[q[0]][q[1]])
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};