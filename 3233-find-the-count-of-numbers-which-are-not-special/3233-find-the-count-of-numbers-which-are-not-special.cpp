class Solution {
public:
    
    bool prime[100000];
    void primes()
    {
        memset(prime, 1, sizeof(prime));
        for (int i = 2; i * i <= 5e4; i++) {
            if (prime[i]) 
            {
                for (int j = i * i; j <= 5e4; j += i)
                    prime[j] = false;
            }
        }
    }
    
    int nonSpecialCount(int l, int r) {
        primes();
        int ans = r - l + 1;
        int a = sqrt(l), b = sqrt(r);
        if(l > a * a)
            a++;
        for(int i = a; i <= b; i++)
            ans -= prime[i];
        if(l == 1)
            ans++;
        return ans;
    }
};