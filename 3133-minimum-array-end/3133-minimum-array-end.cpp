class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Array End.
// Memory Usage: 9.9 MB, less than 9.09% of C++ online submissions for Minimum Array End.
    
    long long minEnd(int n, int x) {
        vector<long long> v(60, 0), v2(60, 0);
        n--;
        for(long long i = 0; i < 30; i++)
        {
            if(x & (1LL << i))
                v[i] = -1;
        }
        
        // for(long long i = 0; i < 30; i++)
        //     cout << v[i] << " ";
        // cout << endl;
        
        for(long long i = 0; i < 30; i++)
        {
            if(n & (1LL << i))
                v2[i] = 1;
        }
        
        // for(long long i = 0; i < 30; i++)
        //     cout << v2[i] << " ";
        // cout << endl;
        // cout << (1LL << 28) << endl;
        
        long long i = 0, j = 0;
        while(i < 30)
        {
            if(v[j] == -1)
            {
                j++;
                continue;
            }
            if(v2[i] == 1)
            {
                v[j] = 1;
            }
            i++;
            j++;
        }
        
        // for(long long i = 0; i < 60; i++)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
        
        
        long long ans = 0;
        for(long long i = 0; i < 60; i++)
        {
            if(abs(v[i]) > 0)
            {
                // cout << (1LL << i) << " ";
                ans += (1LL << abs(i));
            }
        }
        
        return ans;
        
//         for(long long i = 0; i < 60; i++)
//         {
//             if(n && (1 << i))
//             {
//                 v[i] = 1;
//             }
//         }
        
//         for(long long i = 0; i < 60; i++)
//         {
//             if(n && (1 << i))
//                 v2[i] = 1;
//         }
        
//         vector<long long> a;
        
//         for(long long i = 0; i < )
        
    }
};