class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            int x = 0, y = 0;
            for(int i = 0; i < 20; i++)
            {
                if((1 << i) & a)
                    x++;
                if((1 << i) & b)
                    y++;
            }
            if(x == y)
                return a < b;
            return x < y;
        });
        return arr;
    }
};