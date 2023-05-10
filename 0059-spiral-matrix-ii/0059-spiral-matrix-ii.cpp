class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
// Memory Usage: 6.4 MB, less than 90.43% of C++ online submissions for Spiral Matrix II.
    
    vector<vector<int>> generateMatrix(int n) {
        int i = 0;
        int j = 0;
        int is = -1;
        int ie = n;
        int js = -1;
        int je = n;
        vector<vector<int>> v(n, vector<int>(n));
        int k = 1;
        int check = 0;

        int p = pow(n, 2);
        // cout << p << endl;
        // cout << p << endl;

        // v[i][j] = 1;
        // return v;

        while (k <= p)
        {
            // cout << "HII" << endl;
            // cout << i << " " << j << endl;
            v[i][j] = k;

            if (check == 0)
            {
                j++;
            }
            else if (check == 1)
            {
                i++;
            }
            else if (check == 2)
            {
                j--;
            }
            else if (check == 3)
            {
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
                je--;
                i--;
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

            k++;
        }

            // cout << p << endl;
        // if(n % 2 == 1)
        // {
        //     // v[i/2][j/2] = p;
        // }

        // cout << "HII" << endl;
        return v;  
    }
};