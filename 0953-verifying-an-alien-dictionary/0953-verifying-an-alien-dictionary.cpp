class Solution {
public:
    
      bool isAlienSorted(vector<string>& words, string order) {
          int n = words.size();
          int m = order.size();
          unordered_map<char,int> mp;
          
          for(int i = 0; i < m; i++)
          {
              mp[order[i]] = i;
          }
          
          
          for(int i = 1; i < n; i++)
          {
              bool check = false;
              for(int j = 0; j < min(words[i-1].length(), words[i].length()); j++)
              {
                  if(mp[words[i][j]] > mp[words[i-1][j]])
                  {
                      check = true;
                      break;
                  }
                  if(mp[words[i][j]] < mp[words[i-1][j]])
                      return false;
              }
              if(!check && words[i-1].length() > words[i].length())
                  return false;
          }
          return true;
      }
};
    
    
    
//     Runtime: 6 ms, faster than 65.24% of C++ online submissions for Verifying an Alien Dictionary.
// Memory Usage: 9.7 MB, less than 25.79% of C++ online submissions for Verifying an Alien Dictionary.
    
    // What is the difference betweeen this code and down one this one is copied and down one is mine
    
//       bool isAlienSorted(vector<string>& words, string order) {
//         unordered_map<char, int> map;
//         for (int i = 0; i < order.length(); i++) {
//             map[order[i]] = i;
//         }
//         for (int i = 1; i < words.size(); i++) {
//             string first = words[i - 1];
//             string second = words[i];
//             int n = min(first.length(), second.length());
//             bool flag = false;
//             for (int j = 0; j < n; j++) {
//                 if (map[first[j]] < map[second[j]]) {
//                     flag = true;
//                     break;
//                 }
//                 else if (map[first[j]] > map[second[j]]) {
//                     return false;
//                 }
//             }
//             if (!flag && first.length() > second.length()) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
    
//     bool isAlienSorted(vector<string>& words, string order) {
//         int n = words.size();
//         map<char,int> mp;
//         for(int i = 0; i < order.size(); i++)
//         {
//             mp[order[i]] = i;
//         }
        
//         for(int i = 1; i < n; i++)
//         {
//             bool check = false;
//             for(int j = 0; j < min(words[i-1].length(), words[i].length()); j++)
//             {
//                 // cout << mp[words[i-1][j]] << " " << mp[words[i][j]] << endl;
//                  if(mp[words[i-1][j]] < mp[words[i][j]])
//                 {
//                     check = true;
//                     break;
//                 }
//                 // else if(mp[words[i-1][j]] > words[i][j])
//                 else if(mp[words[i][j]] > mp[words[i-1][j]])
//                     return false;
//                 // else if(mp[words[i-1][j]] < mp[words[i][j]])
//                 // {
//                 //     check = true;
//                 //     break;
//                 // }
//             }
//             if(!check && words[i].length() < words[i-1].length())
//                 return false;
//         }
//         return true;
//     }
// };

