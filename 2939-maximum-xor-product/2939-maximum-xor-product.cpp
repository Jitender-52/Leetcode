class Solution
{
public:
    
    const long long mod = 1e9 + 7;

    long long maximumXorProduct(long long c, long long d, long long n)
    {
        long long a = max(c, d), b = min(c, d);
        for (long long i = n - 1; i >= 0; i--)
        {
            if (a <= b && (a & (1LL << i)) == 0)
            {
                a ^= (1LL << i);
                b ^= (1LL << i);
            }
            else if (b <= a && (b & (1LL << i)) == 0)
            {
                a ^= (1LL << i);
                b ^= (1LL << i);
            }
        }
        return ((a % mod) * (b % mod)) % mod;
    }
};
    
    
//     const long long mod = 1e9 + 7;

//     long long fast_power(long long x, long long p)
//     {
//         if (p == 0)
//             return 1;

//         long long ans = fast_power((x * x) % mod, p / 2) % mod;

//         if (p & 1)
//             ans *= x;
//         return ans % mod;
//     }

//     long long maximumXorProduct(long long c, long long d, long long n)
//     {
//         long long a = max(c, d), b = min(c, d);

//         for (long long i = n - 1; i >= 0; i--)
//         {
//             if (a <= b && (a & (1LL << i)) == 0)
//             {
//                 a ^= (1LL << i);
//                 b ^= (1LL << i);
//             }
//             else if (b <= a && (b & (1LL << i)) == 0)
//             {
//                 a ^= (1LL << i);
//                 b ^= (1LL << i);
//             }
//         }

//         vector<long long> x(52), y(52);

//         for (long long i = 0; i < 51; i++)
//         {
//             if (a & (1LL << i))
//                 x[i] = 1;
//             if (b & (1LL << i))
//                 y[i] = 1;
//         }

//         vector<long long> v;
//         for (long long i = 0; i < 51; i++)
//         {
//             for (long long j = 0; j < 51; j++)
//             {
//                 if (x[i] == 1 && y[j] == 1)
//                     v.push_back(i + j);
//             }
//         }

//         long long ans = 0;
//         for (long long i = 0; i < v.size(); i++)
//         {
//             (ans += fast_power(2, v[i])) %= mod;
//         }
//         return ans;
//     }
// };