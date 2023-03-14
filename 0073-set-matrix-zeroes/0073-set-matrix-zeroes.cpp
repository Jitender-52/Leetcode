class Solution {
public:
    
        void setZeroes(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            
            bool check = false;
            for(int i = 0; i < n; i++)
            {
                if(matrix[i][0] == 0)
                    check = true;
            }
            
            for(int i = 0; i < n; i++)
            {
                for(int j = 1; j < m; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
            
            for(int i = 1; i < n; i++)
            {
                for(int j = 1; j < m; j++)
                {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0;
                }
            }
            
            if(matrix[0][0] == 0)
            {
                for(int j = 0; j < m; j++)
                {
                    matrix[0][j] = 0;
                }
            }
            
            if(check)
            {
                for(int i = 0; i < n; i++)
                {
                    matrix[i][0] = 0;
                }
            }   
        }
};
    
    
    
//     Runtime: 18 ms, faster than 43.34% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 13.5 MB, less than 10.04% of C++ online submissions for Set Matrix Zeroes.
    
    
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         set<int> row;
//         set<int> col;
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(matrix[i][j] == 0)
//                 {
//                     row.insert(i);
//                     col.insert(j);
//                 }
//             }
//         }
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(row.find(i) != row.end() || col.find(j) != col.end())
//                     matrix[i][j] = 0;
//             }
//         }
//     }
// };