class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // int a = ((abs(sx - fx) + abs(sy - fy)));
        // cout << a << " " << t << endl;
        // return a <= t;
        
        int a = INT_MAX;
        a = min(abs(sx-fx), a);
        a = min(abs(sy - fy), a);
        
        // return (abs(abs(sx - fx) + abs(sy - fy) - a) <= t);

        int b = (abs(abs(sx - fx) + abs(sy - fy) - a));
        
        if(sx == fx && sy == fy && t == 1)
            return false;
        
        return (abs(abs(sx - fx) + abs(sy - fy) - a) <= t);
        
    }
};