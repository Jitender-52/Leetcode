class Solution {
public:
    
    int minAnagramLength(string s) {
        int n = s.length();
        map<char, int> mp;
        for(auto i : s)
        {
            mp[i]++;
        }
        
        int ans = n;
        for(int i = 1; i <= n; i++)
        {
            if(n % i == 0)
            {
                string x = s.substr(0, i);
                sort(x.begin(), x.end());
                bool check = true;
                for(int j = 0; j < n; j += i)
                {
                    string y = s.substr(j, i);
                    sort(y.begin(), y.end());
                    if(x != y)
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                    return i;
            }
        }
        return ans;
    }
};
    
    
//     int minAnagramLength(string s) {
//         int n = s.length();
//         map<char, int> mp;
//         for(auto i : s)
//         {
//             mp[i]++;
//         }
        
//         int ans = n;
//         for(int i = 1; i <= n; i++)
//         {
//             if(n % i == 0)
//             {
//                 int x = n / i;
//                 bool check = true;
//                 for(auto it : mp)
//                 {
//                     if(it.second % i != 0)
//                     {
//                         check = false;
//                         break;
//                     }
//                 }
//                 if(check)
//                     ans = min(ans, x);
//             }
//         }
//         return ans;
//     }
// };