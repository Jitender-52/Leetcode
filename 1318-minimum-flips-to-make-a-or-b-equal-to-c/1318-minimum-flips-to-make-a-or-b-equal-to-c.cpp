class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x = a | b;
        int ans = 0;
        
        for(int i = 0; i < 31; i++)
        {
            int abit = a & (1 << i);
            int bbit = b & (1 << i);
            int cbit = c & (1 << i);
            if(!cbit && abit)
                ans++;
            if(!cbit && bbit)
                ans++;
            if(cbit && !(abit | bbit))
                ans++;
        }
        
        // cout << x << " " << c << endl;
        // for(int i = 0; i < 31; i++)
        // {
        //     // cout << (1 << i) << endl;
        //     int xbit = (x & (1 << i));
        //     int cbit = (c & (1 << i));
        //     cout << xbit << " " << cbit << endl;
        //     // cout << (xbit ^ cbit) << endl;
        //     // ans += (xbit ^ cbit);
        //     // ans += 1 ^ !(xbit ^ cbit);
        //     if((xbit ^ cbit) > 0)
        //         ans++;
        // }
        return ans;
    }
};