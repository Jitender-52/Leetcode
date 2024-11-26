class Solution {
public:
    
//     Runtime: 56 ms, faster than 21.96% of C++ online submissions for Find Champion II.
// Memory Usage: 104.9 MB, less than 19.54% of C++ online submissions for Find Champion II.
    
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n+1, 0);
        for(auto i : edges)
        {
            indegree[i[1]]++;
        }
        
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
                count++;
        }
        
        if(count != 1)
            return -1;
        
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
                return i;
        }
        return -1;
    }   
};