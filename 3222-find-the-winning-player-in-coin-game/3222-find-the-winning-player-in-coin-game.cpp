class Solution {
public:
    string losingPlayer(int x, int y) {
        int ans = 1;
        while(x > 0 && y > 3)
        {
            x--;
            y -= 4;
            ans ^= 1;
        }
        if(ans == 0)
            return "Alice";
        else
            return "Bob";
    }
};