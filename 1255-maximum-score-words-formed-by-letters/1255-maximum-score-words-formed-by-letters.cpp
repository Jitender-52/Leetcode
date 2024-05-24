class Solution {
public:

//     Runtime: 12 ms, faster than 51.65% of C++ online submissions for Maximum Score Words Formed by Letters.
// Memory Usage: 17 MB, less than 71.26% of C++ online submissions for Maximum Score Words Formed by Letters.
    
    
//     Runtime: 19 ms, faster than 64.71% of C++ online submissions for Maximum Score Words Formed by Letters.
// Memory Usage: 14 MB, less than 69.71% of C++ online submissions for Maximum Score Words Formed by Letters.
    
    
    int maxScore(int j, vector<string> &words, unordered_map<char,int> mp, vector<int> &score)
    {
        int n = words.size();
        if(j >= n)
            return 0;
        
        int sum = 0;
        if(j > -1)
        {
            for(int i = 0; i < words[j].length(); i++)
            {
                if(mp[words[j][i]] == 0)
                    return 0;
                else
                {
                    mp[words[j][i]]--;
                    sum += score[words[j][i] - 'a'];
                }
            }
        }
        
        // cout << j << endl;
        
        int ans = 0;
        
        for(int i = j+1; i < n; i++)
        {
            ans = max(ans, maxScore(i, words, mp, score));
        }
        
        // ans = max(ans, maxScore(j+1, words, mp, score));
        // ans = max(ans, maxScore(j+2, words, mp, score));
        return ans + sum;
    }
        
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        
        unordered_map<char,int> mp;
        for(int i = 0; i < letters.size(); i++)
        {
            mp[letters[i]]++;
        }
        
        return maxScore(-1, words, mp, score);
    }
};



    
    // int maxScore(int j, vector<string> &words, vector<char> &letters, vector<int> &score)
    // {
    //     int ans = 0;
    //     for(int i = j; i < n; i++)
    //     {
    //         bool check = true;
    //         int sum = 0;
    //         for(int k = 0; k < words[i]; k++)
    //         {
    //             if(mp[words[i][k]] < 1)
    //             {
    //                 check = false;
    //                 break;
    //             }
    //             sum += score[words[i][k] - 'a'];
    //         }
    //         if(!check)
    //             break;
    //         ans = max(ans, sum + )
    //     }
    // }
    
//     int maxScore(int j, vector<string> &words, map<char,int> m, vector<int> &score)
//     {
//         int n = words.size();
        
//         if(j >= n)
//             return 0;
        
//         int ans = 0;
//         for(int i = j+1; i < n; i++)
//         {
//            map<char,int> mp = m;
//            for(int k = 0; k < words[i].length(); k++)
//            {
//                if(mp[words[i][k]] == 0)
//                {
//                     break;
//                }
//                else
//                {
//                    mp[words[i][k]]--;
//                }
//                if(k == words[i].length() - 1)
//                {
//                    ans = max(ans, maxScore(i, words, mp, score));
//                }
//            }
//         }
//     }


