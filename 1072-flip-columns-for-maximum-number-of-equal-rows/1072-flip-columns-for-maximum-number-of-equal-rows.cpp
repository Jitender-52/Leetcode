class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternFrequency;

        for (auto& currentRow : matrix) 
        {
            string patternBuilder = "";
            for (int col = 0; col < currentRow.size(); col++) 
            {
                if (currentRow[0] == currentRow[col]) 
                    patternBuilder += "T";
                else 
                    patternBuilder += "F";
            }
            patternFrequency[patternBuilder]++;
        }

        int maxFrequency = 0;
        for (auto& entry : patternFrequency) 
            maxFrequency = max(entry.second, maxFrequency);
        return maxFrequency;
    }
};
    
//     int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         map<string, int> mp;
//         for(int j = 0; j < m; j++)
//         {
//             string s = "";
//             for(int i = 0; i < n; i++)
//                 s += ('0' + matrix[i][j]);
//             mp[s]++;
//             cout << s << endl;
//             s = "";
//             for(int i = 0; i < n; i++)
//                 s += ('0' + (1 - matrix[i][j]));
//             mp[s]++;
//             // cout << s << endl;
//         }
//         int ans = 0;
//         for(auto i : mp)
//             ans = max(ans, i.second);
//         return ans;
//     }
// };