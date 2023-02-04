class Solution {
public:
    
        bool checkInclusion(string s1, string s2) {
            int n = s1.length();
            int m = s2.length();
            
            if(n > m)
                return false;
            
            map<int,int> mp;
            for(int i = 0; i < n; i++)
            {
                mp[s1[i]]++;
            }
            
            int count = 0;
            
            map<int,int> mp2;
            int i = 0;
            for(i = 0; i < n; i++)
            {
                mp2[s2[i]]++;
            }
            
            char c = 'a';
            for(int i = 0; i < 26; i++)
            {
                if(mp[c] == mp2[c])
                    count++;
                c++;
            }
            
            int s = 0;
            
            if(count == 26)
                return true;
            // cout << mp2.size() << endl;
            for(i; i < m; i++)
            {
                // cout << i <<  " " << count << endl;
                
                if(mp2[s2[i]] == mp[s2[i]])
                    count--;
                if(mp2[s2[s]] == mp[s2[s]])
                    count--;
                
                mp2[s2[i]]++;
                mp2[s2[s]]--;
                
                if(mp2[s2[i]] == mp[s2[i]])
                    count++;
                if(mp2[s2[s]] == mp[s2[s]])
                    count++;
                
                //  for(auto i : mp)
                //     cout << i.second << " ";
                // cout << endl;
                // for(auto i : mp2)
                //     cout << i.second << " ";
                // cout << endl;
                
                if(count == 26)
                    return true;
                s++;
            }
            return false;
        }
};
    
    
    
    
//     Runtime: 2265 ms, faster than 5.02% of C++ online submissions for Permutation in String.
// Memory Usage: 93.3 MB, less than 5.01% of C++ online submissions for Permutation in String.
    
    
//     bool checkInclusion(string s1, string s2) {
//         int n = s1.length();
//         int m = s2.length();
//         map<char,int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             mp[s1[i]]++;
//         }
//         for(int i = 0; i <= m - n; i++)
//         {
//             map<char,int> mp1;
//             for(int j = i; j < i + n; j++)
//             {
//                 // cout << j <<" ";
//                 mp1[s2[j]]++;
//             }
//             // cout << endl;
//             if(mp == mp1)
//                 return true;
//         }
//         return false;
//     }
// };