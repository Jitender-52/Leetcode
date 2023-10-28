class Solution {
public:
    
    const int mod = 1e9+7;
    
    int countVowelPermutation(int n) {
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        long long a1, e1, i1, o1, u1;
        for(int k = 2; k <= n; k++)
        {
            a1 = (i + e + u) % mod;
            e1 = (a + i) % mod;
            i1 = (o + e) % mod;
            o1 = (i) % mod;
            u1 = (o + i) % mod;
            a = a1;
            e = e1;
            i = i1;
            o = o1;
            u = u1;
        }
        return (a + e + i + o + u) % mod;
        
        
//         long a = 1, e = 1, i = 1, o = 1, u = 1, mod = pow(10, 9)+7;
//         long a2, e2, i2, o2, u2; 
        
//         for (int j = 2; j <= n; j++) {
//             a2 = (e + i + u) % mod;
//             e2 = (a + i) % mod;
//             i2 = (e + o) % mod;
//             o2 = i;
//             u2 = (o + i) % mod;
            
//             a = a2, e = e2, i = i2, o = o2, u = u2;
//         }
//         return (a + e + i + o + u) % mod;
    }
};

// e - a
// a,i -  e
