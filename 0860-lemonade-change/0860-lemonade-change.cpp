class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(auto i : bills)
        {
            int a = i;
            i -= 5;
            if(i >= 10 && ten)
            {
                i -= 10;
                ten--;
            }
            while(i >= 5 && five)
            {
                i -= 5;
                five--;
            }
            if(i > 0)
                return false;
            if(a == 5)
                five++;
            else if(a == 10)
                ten++;
        }
        return true;
    }
};