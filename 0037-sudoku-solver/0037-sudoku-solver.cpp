class Solution {
public:
    
    bool solve(int r, int c, vector<vector<char>> &board, vector<vector<vector<int>>> &v, vector<vector<int>> &row, vector<vector<int>> &col)
    {
        int n = board.size();
        if(r >= n)
            return true;
        if(c >= n)
        {
            r++;
            c = 0;
            return solve(r, c, board, v, row, col);
        }

        if(board[r][c] == '.')
        {
            for(char a = '1'; a <= '9'; a++)
            {
                int i = (a - '0');
                if(!v[r/3][c/3][i] && !row[r][i] && !col[c][i])
                {
                    v[r/3][c/3][i] = 1;
                    row[r][i] = 1;
                    col[c][i] = 1;
                    board[r][c] = a;
                    if(solve(r, c+1, board, v, row, col))
                        return true;
                    v[r/3][c/3][i] = 0;
                    row[r][i] = 0;
                    col[c][i] = 0;
                    board[r][c] = '.';
                }
            }
        }
        else
        {
            return solve(r, c+1, board, v, row, col);
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<vector<int>>> v(3, vector<vector<int>> (3, vector<int> (10, 0)));
        vector<vector<int>> row(n, vector<int> (10, 0));
        vector<vector<int>> col(n, vector<int> (10, 0));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] != '.')
                {
                    int a = board[i][j] - '0';
                    v[i/3][j/3][a] = 1;
                    row[i][a] = 1;
                    col[j][a] = 1;
                }
            }
        }
        
        solve(0, 0, board, v, row, col);
    }
};
    
    
    
    
//     bool sudoku(int r, int c, vector<vector<int>> row, vector<vector<int>> col, vector<vector<char>> &board, vector<vector<vector<int>>> v)
//     {
//         cout << endl;        
//         cout << r << " " << c << endl;
//         int n = board.size();
//         if(r >= n)
//         {
//             return true;
//         }
        
//         if(c >= n)
//             c = 0;
        
//         char a = '1';
//         for(int i = 0; i < 9; i++)
//         {
//             cout << board[r][c] << " " << v[r/3][c/3][a-'0'] << row[r][a-'0'] << col[c][a-'0'] << endl;
//             if(board[r][c] != '.')
//             {
//                 sudoku(r, c+1, row, col, board, v);
//             }
//             cout << a << endl;
//             if(board[r][c] == '.' && !v[r/3][c/3][a - '0'] && !row[r][a - '0'] && !col[c][a - '0'])
//             {
//                 board[r][c] = a;
//                 row[r][a - '0'] = 1;
//                 col[c][a - '0'] = 1;
//                 v[r/3][c/3][a - '0'] = 1;
//                 if(sudoku(r, c+1, row, col, board, v))
//                     return true;
//                 row[r][a - '0'] = 0;
//                 col[c][a - '0'] = 0;
//                 v[r/3][c/3][a - '0'] = 0;
//                 board[r][c] ='.';
//             }
//             // cout << a << endl;
//             a++;
//         }
//         return false;
//     }
    
//     void solveSudoku(vector<vector<char>>& board) {
//         int n = board.size();
//         cout << n << endl;
//         // map<vector<vector<vector<int>>>, bool> mp;
//         vector<vector<vector<int>>> v(3, vector<vector<int>> (3, vector<int> (10, 0)));
//         vector<vector<int>> row(n, vector<int> (10, 0));
//         vector<vector<int>> col(n, vector<int> (10, 0));
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(board[i][j] != '.')
//                 {
//                     row[i][board[i][j] - '0'] = 1;
//                     col[j][board[i][j] - '0'] = 1;
//                     v[i/3][j/3][board[i][j] - '0'] = 1;
//                 }
//             }
//         }
        
// //         for(int i = 0; i < n; i++)
// //         {
// //             for(int j = 1; j <= n; j++)
// //             {
// //                 cout << row[i][j] << " ";
// //             }
// //             cout << endl;
// //         }
// //         cout << endl;
        
// //         for(int i = 0; i < n; i++)
// //         {
// //             for(int j = 1; j <= n; j++)
// //             {
// //                 cout << col[i][j] << " ";
// //             }
// //             cout << endl;
// //         }
// //         cout << endl;
        
// //          for(int i = 0; i < 3; i++)
// //         {
// //             for(int j = 0; j < 3; j++)
// //             {
// //                 for(int k = 1; k <= 9; k++)
// //                 {
// //                     cout << v[i][j][k] << " ";
// //                 }
// //                 cout << endl;
// //             }
// //             // cout << endl;
// //         }
// //         cout << endl;
        
//         sudoku(0, 0, row, col, board, v);
//     }
// };