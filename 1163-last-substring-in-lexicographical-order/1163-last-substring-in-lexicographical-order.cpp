class Solution {
public:
    
        string lastSubstring(string s) {
            int n = s.length();
            int i = 0, j = 1, k = 0;
            
            while(j < n)
            {
                if(s[i+k] < s[j+k])
                {
                    i = max(i+k, j);
                    j = i + 1;
                    k = 0;
                }
                else if(s[i+k] > s[j+k])
                {
                    j = j + k + 1;
                    k = 0;
                }
                else
                {
                    k++;
                }
            }
            return s.substr(i);
        }
};
    
    
    
//     string find(string &s, string &t){
            
//         int n = min(s.length(), t.length());
//         for(int i = 0; i < n; i++)
//         {
//             if(s[i] > t[i])
//                 return s;
//             else if(t[i] > s[i])
//                 return t;
//         }
//         if(s.length() > t.length())
//             return s;
//         return t;
//     }
    
//     int find(string &s, int last, int curr)
//     {
//         int n = s.length();
//         int i = last;
//         int j = curr;
//         // cout << i << " " << j << endl;
//         while(j < n)
//         {
//             if(s[j] > s[i])
//                 return curr;
//             else if(s[j] < s[i])
//                 return last;
//             i++;
//             j++;
//         }
//         return last;
//     }
    
//     string lastSubstring(string s) {
//         int n = s.length();

//         string ans = "";
//         int last = 0;
//         for(int i = 1; i < n; i++)
//         {
//             last = find(s, last, i);
//             // string p = s.substr(i);
//             // ans = find(ans, p);
//         }
//         // cout << last << endl;
//         // return ans;
//         return s.substr(last);
//     }
// };
    

//     string find(string s, string t)
//     {
//         int n = min(s.length(), t.length());
//         for(int i = 0; i < n; i++)
//         {
//             if(s[i] > t[i])
//                 return s;
//             else if(t[i] > s[i])
//                 return t;
//         }
//         if(s.length() > t.length())
//             return s;
//         return t;
//     }
    
//     string lastSubstring(string s) {
//         string ans = "";
//         char c = 'a';
//         for(int i = 0; i < n; i++)
//         {
//             if(s[i] > c)
//                 c = s[i];
//         }
        
//         int maxi = 0;
//         for(int i = 0; i < n; i++)
//         {
//             int count = 0;
//             while(i < n && s[i] == c)
//                 count++;
//             maxi = max(maxi, count);
//         }
        
        
        
//         for(int i = 0; i < maxi; i++)
//         {
//             ans += c;
//         }
        
//         for(int i = 0; i < n - maxi; i++)
//         {
            
//         }
//     }
// };