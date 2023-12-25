class Solution {
public:
    
    int Decodings(int i, string s, vector<int> &v)
    {
        int n = s.length();
        
        if(i == n)
            return 1;
        
        if(v[i] != -1)
            return v[i];
        
         if(s[i] == '0')
        {
            return v[i] = 0;
        }
        
        int sum = 0;
       
        if(i <= n-1 && s[i] != '0')
        {
            sum += Decodings(i+1, s, v);
        }
        if(i < n-1 && s[i] == '1')
        {
            sum += Decodings(i+2, s, v);
            // cout << Decodings(i+2,s,v);
        }
        if(i < n-1 && s[i] == '2' && s[i+1] - '0' < '7' - '0')
        {
            sum += Decodings(i+2, s, v);
        }
        return v[i] = sum;
    }
    
    int numDecodings(string s) {
        int n = s.length();
        if(s[0] == '0')
        {
            return 0;
        }
        for(int i = 1; i < n; i++)
        {
            if(s[i] == '0' && s[i-1] - '0' > '2' - '0')
                return 0;
            if(s[i] == '0' && s[i-1] == '0')
                return 0;
        }
        vector<int> v(n+3, -1);
        return Decodings(0, s, v);
    }
};
    
    
    
//          Time Limit Exceeded
    
//     int numDecodings(string s) {
//       if (s.length() == 0)
//     {
//         return 1;
//     }

//     // if (s[0] - '0' == 0)
//     if (s[0] == '0')
//     {
//         return 0;
//     }

//     string s1 = s.substr(1);

//     int w1 = numDecodings(s1);
//     int w2 = 0;
//     if (s.length() > 1)
//     {
//         int first = s[0] - '0';
//         int second = s[1] - '0';
//         if (first * 10 + second <= 26)
//         // if (first <= 2 && second <= 6)
//         {
//             w2 = numDecodings(s.substr(2));
//         }
//     }

//     // int w1 = numDecodings(s.substr(1));
//     // int w2 = 0;
//     // if (s.length() >= 2)
//     // {
//     //     int first = s[0] - '0';
//     //     int second = s[1] - '0';
//     //     if ((first * 10) + second <= 26)
//     //     {
//     //         w2 = numDecodings(s.substr(2));
//     //     }
//     // }

//     return w1 + w2;   
//     }
// };